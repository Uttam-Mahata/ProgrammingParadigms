#include <iostream>
using namespace std;

class MyStack {
	private:
		int top;
		int capacity;
		int* array;
	public:
		void initializeStack(int capacity) {
			top = -1;
			array = new int[capacity];

		}
		void Push() {



		}
		void Pop () {

		}
		void MaxSize() {

		}
		void CurrentSize() {

		}
		bool IsEmpty() {

		}
		void Display() {

		}
};

int main() {
	int n;
	cout << "Enter the number of stacks:";
	cin >> n;
	MyStack s[n];

	for(int i = 0; i < n ; i++) {
		s[i].initializeStack();
		
		if(s[i].top == s[i].capacity - 1) {
			cout << "Stack Overflow\n";

		} else {
			++s[i].top;
			s[i].Push();

		}


	}


return 0;
}
