#include <iostream>
#include <vector>

using namespace std;

class MyStack {
private:
    int maxSize;
    vector<int> stack;
public:
    MyStack(int size) : maxSize(size) {}

    void Push(int element) {
        if (stack.size() < maxSize) {
            stack.push_back(element);
            cout << "Element " << element << " pushed into the stack.\n";
        } else {
            cout << "Stack overflow! Cannot push more elements.\n";
        }
    }

    void Pop() {
        if (!stack.empty()) {
            int poppedElement = stack.back();
            stack.pop_back();
            cout << "Element " << poppedElement << " popped from the stack.\n";
        } else {
            cout << "Stack underflow! Cannot pop from an empty stack.\n";
        }
    }

    int MaxSize() {
        return maxSize;
    }

    int CurrentSize() {
        return stack.size();
    }

    bool IsEmpty() {
        return stack.empty();
    }

    void Display() {
        cout << "Stack content: ";
        if (!stack.empty()) {
            for (int i : stack) {
                cout << i <<"\n";
            }
        } else {
            cout << "Empty";
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter the size of the stack: ";
    cin >> size;

    MyStack stack(size);

    char choice;
    do {
        cout << "\nChoose operation:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display\n";
        cout << "4. Current Size\n";
        cout << "5. Max Size\n";
        cout << "6. Is Empty\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                int element;
                cout << "Enter element to push: ";
                cin >> element;
                stack.Push(element);
                break;
            }
            case '2':
                stack.Pop();
                break;
            case '3':
                stack.Display();
                break;
            case '4':
                cout << "Current size of the stack: " << stack.CurrentSize() << endl;
                break;
            case '5':
                cout << "Max size of the stack: " << stack.MaxSize() << endl;
                break;
            case '6':
                cout << "Stack is " << (stack.IsEmpty() ? "empty" : "not empty") << endl;
                break;
            case '7':
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != '7');

    return 0;
}
