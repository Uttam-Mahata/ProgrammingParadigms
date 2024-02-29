//
// Created by uttam on 22-01-2024.
//
#include <iostream>
using namespace std;

struct MyStack {
    int top;
    int capacity;
    int *array;
};

MyStack* initializeStack(int capacity) {
    MyStack* s = new MyStack();
    s->capacity = capacity;
    s->top = -1;
    s->array = new int[s->capacity];
    return s;
}

void push(MyStack* s, int item) {
    if (s->top == s->capacity - 1) {
        cout << "Stack Overflow\n";
    } else {
        s->array[++s->top] = item;
    }
}

int pop(MyStack* s) {
    if (s->top == -1) {
        cout << "Stack Underflow\n";
        return -1;
    } else {
        return s->array[s->top--];
    }
}

int getMaxSize(MyStack* s) {
    return s->capacity;
}

int currentSize(MyStack* s) {
    return s->top + 1;
}

bool isEmpty(MyStack* s) {
    return s->top == -1;
}
void freeMemory(MyStack* s) {
    delete[] s->array;
    delete s;
}

int main() {
    MyStack* s = initializeStack(10);
    
   int size = 10;
  int arr[size];
cout << "Enter the elements to Push the element to stack: "<< endl;
for (int i = 0; i < 10; i ++) {
        cin >> arr[i];
    }
cout << "\n";


    for (int i = 0; i < 10; i ++) {
        push(s, arr[i]);
    }

    cout << "Elements of stack s:\n";
    while (!isEmpty(s)) {
        cout << pop(s) << endl;
    }

    cout << "Current size of stack s: " << currentSize(s) << endl;
    cout << "Max size of stack s: " << getMaxSize(s) << endl;

    MyStack* s2 = initializeStack(4);

 int size2 = 10;
  int arr2[size];
cout << "Enter the elements to Push the element to stack: "<< endl;
for (int i = 0; i < 10; i ++) {
        cin >> arr[i];
    }
cout << "\n";


    for (int i = 0; i < 10; i++) {
        push(s2, arr2[i]);
    }

    cout << "\nElements of stack s2:\n";
    while (!isEmpty(s2)) {
        cout << pop(s2) << endl;
    }

    cout << "Current size of stack s2: " << currentSize(s2) << endl;
    cout << "Max size of stack s2: " << getMaxSize(s2) << endl;


    freeMemory(s);

    return 0;
}

