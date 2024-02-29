#include <iostream>
#include <stdexcept>
using namespace std;

const int maxStacks = 5;
static int stackCount = 0;

template <typename T> class MyStack {
private:
  const int maxSize;
  T *arr;
  int top;

public:
  MyStack(int size) : maxSize(size), top(-1) {
    if (stackCount >= maxStacks) {
      throw overflow_error("Maximum number of stacks exceeded");
    }
    ++stackCount;
    arr = new T[maxSize];
  }

  MyStack(const MyStack &other) : maxSize(other.maxSize), top(other.top) {
    arr = new T[maxSize];
    for (int i = 0; i <= top; ++i)
      arr[i] = other.arr[i];
  }

  ~MyStack() {
    --stackCount;
    delete[] arr;
  }

  void push(T element) {
    if (top == maxSize - 1) {
      cout << "Stack Overflow!" << endl;
      return;
    }
    arr[++top] = element;
  }

  T pop() {
    if (top == -1) {
      cout << "Stack Underflow!" << endl;
      return T();
    }
    return arr[top--];
  }

  int getMaxSize() const { return maxSize; }

  int getCurrentSize() const { return top + 1; }

  bool isEmpty() const { return top == -1; }

  void display() const {
    if (isEmpty()) {
      cout << "Stack is empty" << endl;
      return;
    }
    cout << "Stack content: ";
    for (int i = 0; i <= top; ++i)
      cout << arr[i] <<"\n";
    cout << endl;
  }

  MyStack &operator=(const MyStack &other) {
    if (this != &other) {
      delete[] arr;
      top = other.top;
      arr = new T[maxSize];
      for (int i = 0; i <= top; ++i)
        arr[i] = other.arr[i];
    }
    return *this;
  }

  MyStack operator+(const MyStack &other) const {
    if (maxSize != other.maxSize) {
      throw invalid_argument("Stack sizes do not match");
    }
    MyStack result(maxSize);
    for (int i = 0; i <= top; ++i)
      result.push(arr[i]);
    for (int i = 0; i <= other.top; ++i)
      result.push(other.arr[i]);
    return result;
  }
};

int main() {
  try {
    int size1,size2;
    cout << "Enter the size of the stack1: ";
    count << "Enter the size of the stack2: ";
    cin >> size1;
    cin >> size2;

    MyStack<int> intStack(size1);
    MyStack<int> intStack2(size2);

    int element;
    cout << "Enter elements for intStack: ";
    for (int i = 0; i < size; ++i) {
      cin >> element;
      intStack.push(element);
    }

    cout << "Enter elements for intStack2: ";
    for (int i = 0; i < size2; ++i) {
      cin >> element;
      intStack2.push(element);
    }

    MyStack<int> intStack3 = intStack + intStack2;
    cout << "Stack 3 content after adding Stack 1 and Stack 2: ";
    intStack3.display();

    cout << "Number of stacks created: " << stackCount << endl;
  } catch (const exception &e) {
    cout << "Exception occurred: " << e.what() << endl;
  }

  return 0;
}
