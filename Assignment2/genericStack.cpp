#include <iostream>
using namespace std;

struct MyStruct {
    int value1;
    double value2;
};

template <typename T>
struct MyStack {
    int top;
    int capacity;
    T* array;
};

template <typename T>
MyStack<T>* initializeStack(int capacity) {
    MyStack<T>* s = new MyStack<T>();
    s->capacity = capacity;
    s->top = -1;
    s->array = new T[s->capacity];
    return s;
}

template <typename T>
void push(MyStack<T>* s, T item) {
    if (s->top == s->capacity - 1) {
        cout << "Stack Overflow\n";
    } else {
        s->array[++s->top] = item;
    }
}

template <typename T>
T pop(MyStack<T>* s) {
    if (s->top == -1) {
        cout << "Stack Underflow\n";
        return T();
    } else {
        return s->array[s->top--];
    }
}

template <typename T>
int getMaxSize(MyStack<T>* s) {
    return s->capacity;
}

template <typename T>
int currentSize(MyStack<T>* s) {
    return s->top + 1;
}

template <typename T>
bool isEmpty(MyStack<T>* s) {
    return s->top == -1;
}

template <typename T>
void freeMemory(MyStack<T>* s) {
    delete[] s->array;
    delete s;
}

int main() {
    cout << "Enter data type for stack (int, short, float, double, struct): ";
    string dataType;
    cin >> dataType;

    if (dataType == "int" || dataType == "short" || dataType == "float" || dataType == "double" || dataType == "struct") {
        cout << "Enter capacity for stack: ";
        int capacity;
        cin >> capacity;

        if (dataType == "int") {
            MyStack<int>* s = initializeStack<int>(capacity);
            cout << "Stack created with capacity " << capacity << endl;
          for (int i = 0; i < capacity; i++) {
            int value;
            cin >> value;
            push(s, value);
            
          }
          cout << "Elements of stack s:\n";
          while (!isEmpty(s)) {
              cout << pop(s) << endl;
          }
          cout << "Current size of stack s: " << currentSize(s) << endl;
          cout << "Max size of stack s: " << getMaxSize(s) << endl;

          freeMemory(s);
          
        } else if (dataType == "short") {
            MyStack<short>* s = initializeStack<short>(capacity);

            cout << "Enter elements for stack (short): ";
            for (int i = 0; i < capacity; ++i) {
                short element;
                cin >> element;
                push(s, element);
            }

            cout << "Elements of stack s:\n";
            while (!isEmpty(s)) {
                cout << pop(s) << endl;
            }

            cout << "Current size of stack s: " << currentSize(s) << endl;
            cout << "Max size of stack s: " << getMaxSize(s) << endl;

            freeMemory(s);
        } else if (dataType == "float") {
            MyStack<float>* s = initializeStack<float>(capacity);
            cout << "Enter elements for stack (float): ";
            for (int i = 0; i < capacity; ++i) {
                float element;
                cin >> element;
                push(s, element); 
              
            }
            cout << "Elements of stack s:\n";
            while (!isEmpty(s)) {
                cout << pop(s) << endl; 
              
            }
            cout << "Current size of stack s: " << currentSize(s) << endl;
            cout << "Max size of stack s: " << getMaxSize(s) << endl;
            freeMemory(s);
              
        } else if (dataType == "double") {
            MyStack<double>* s = initializeStack<double>(capacity);
            cout << "Enter elements for stack (double): ";
            for (int i = 0; i < capacity; ++i) {
                double element; 
                cin >> element;
                push(s, element);
            }
            cout << "Elements of stack s:\n";
            while (!isEmpty(s)) {
                cout << pop(s) << endl; 
            }
            cout << "Current size of stack s: " << currentSize(s) << endl;
            cout << "Max size of stack s: " << getMaxSize(s) << endl;
            freeMemory(s);
        
    } else if (dataType == "struct") {
          cout << "Enter capacity for stack of structs: ";
              int capacity;
              cin >> capacity;

              MyStack<MyStruct>* s = initializeStack<MyStruct>(capacity);

              cout << "Enter elements for stack (struct - value1 value2): ";
              for (int i = 0; i < capacity; ++i) {
                  MyStruct element;
                  cin >> element.value1 >> element.value2;
                  push(s, element);
              }

              cout << "Elements of stack s:\n";
              while (!isEmpty(s)) {
                  MyStruct poppedStruct = pop(s);
                  cout << "value1: " << poppedStruct.value1 << ", value2: " << poppedStruct.value2 << endl;
              }

              cout << "Current size of stack s: " << currentSize(s) << endl;
              cout << "Max size of stack s: " << getMaxSize(s) << endl;

              freeMemory(s);
          }
          
    
        else {
        cout << "Invalid data type. Supported types: int, short, float, double, struct." << endl;
    }
    }

    return 0;

}
