#include <iostream>
using namespace std;

struct Point {
  int x;
  int y;
};

ostream &operator<<(ostream &os, const Point &p) {
  os << "(" << p.x << ", " << p.y << ")";
  return os;
}

template <typename T> class MyStack {
private:
  const int maxSize;
  T *arr;
  int top;

public:
  MyStack(int size) : maxSize(size), top(-1) { arr = new T[maxSize]; }

  MyStack(const MyStack &other) : maxSize(other.maxSize), top(other.top) {
    arr = new T[maxSize];
    for (int i = 0; i <= top; ++i)
      arr[i] = other.arr[i];
  }

  ~MyStack() { delete[] arr; }

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
      cout << arr[i] << " ";
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
};

int main() {
  int intsize, shortsize, floatsize, doublesize, structsize;
  cout << "Enter the sizes of the int short float double struct stack: ";
  cin >> intsize >> shortsize >> floatsize >> doublesize >> structsize;

  MyStack<int> intStack(intsize);
  MyStack<short> shortStack(shortsize);
  MyStack<float> floatStack(floatsize);
  MyStack<double> doubleStack(doublesize);
  MyStack<Point> structStack(structsize);

  int choice;
  while (true) {
    cout << "\n1. Push to int stack\n2. Push to short stack\n3. Push to float "
            "stack\n4. Push to double stack\n5. Push to struct stack\n";
    cout << "6. Pop from int stack\n7. Pop from short stack\n8. Pop from float "
            "stack\n9. Pop from double stack\n10. Pop from struct stack\n";
    cout << "11. Display int stack\n12. Display short stack\n13. Display float "
            "stack\n14. Display double stack\n15. Display struct stack\n";
    cout << "16. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1: {
      int element;
      cout << "Enter element to push to int stack: ";
      cin >> element;
      intStack.push(element);
      break;
    }
    case 2: {
      short element;
      cout << "Enter element to push to short stack: ";
      cin >> element;
      shortStack.push(element);
      break;
    }
    case 3: {
      float element;
      cout << "Enter element to push to float stack: ";
      cin >> element;
      floatStack.push(element);
      break;
    }
    case 4: {
      double element;
      cout << "Enter element to push to double stack: ";
      cin >> element;
      doubleStack.push(element);
      break;
    }
    case 5: {
      Point element;
      cout << "Enter x-coordinate: ";
      cin >> element.x;
      cout << "Enter y-coordinate: ";
      cin >> element.y;
      structStack.push(element);
      break;
    }
    case 6:
      cout << "Popped element from int stack: " << intStack.pop() << endl;
      break;
    case 7:
      cout << "Popped element from short stack: " << shortStack.pop() << endl;
      break;
    case 8:
      cout << "Popped element from float stack: " << floatStack.pop() << endl;
      break;
    case 9:
      cout << "Popped element from double stack: " << doubleStack.pop() << endl;
      break;
    case 10: {
      Point p = structStack.pop();
      cout << "Popped element from struct stack: " << p << endl;
      break;
    }
    case 11:
      intStack.display();
      break;
    case 12:
      shortStack.display();
      break;
    case 13:
      floatStack.display();
      break;
    case 14:
      doubleStack.display();
      break;
    case 15:
      structStack.display();
      break;
    case 16:
      return 0;
    default:
      cout << "Invalid choice! Please try again." << endl;
    }
  }

  return 0;
}
