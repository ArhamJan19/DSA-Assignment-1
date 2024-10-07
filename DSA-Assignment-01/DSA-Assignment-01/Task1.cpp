#include<iostream>
#include<string>

using namespace std;

class Stack {
private:

	int top;
	int* stack;
	int min;
	int maxSize;

public:

	Stack(int maxSize) {
		top = -1;
		stack = new int[maxSize];
		this->maxSize = maxSize;
	}

	~Stack() {
		delete[] stack;
	}
		
	bool isEmpty() {
		return (top == -1);
	}

	bool isFull() {
		return (top == this->maxSize - 1);
	}

	void Push(int item) {
		if(isFull()){
			cout << "Stack Overflow " << item << endl;
			return;
		}
		else {
			if (top == -1) {
				min = item;
				stack[++top] = item;
			}
			else if (item < min)
			{
				stack[++top] = 2 * item - min;
				min = item;
			}
			else {
				stack[++top] = item;
			}
				
		
		}
		
	}

	void Pop(int & item) {
		if (isEmpty()) {
			cout << "Stack Underflow" << endl;
			return;
		}
		else {
			int i = stack[top--];
			if (i < min) {
				item = min;
				min = 2 * min - i;
			}
			else if (top == 0) {
				item = i;
			}
			else {
				item = i;
			}
		}
	}

	int Size() {
		return top + 1;
	}

	int getMin() {
		return this->min;
	}
};


void Menu() {
	cout << "\n---------- Main Menu -----------\n";
	cout << "\n1.Push";
	cout << "\n2.Pop";
	cout << "\n3.Size";
	cout << "\n4.Minimum";
	cout << "\n5.Greater Next Value";
	cout << "\n6.Exit";
	cout << "\n\nEnter your Choice: ";
}

void GreaterNextElement(int array[], const int size) {

	Stack stack = Stack(size);
	int *result = new int[size];

	for (int i = size - 1; i >= 0; i--) {
		while (!stack.isEmpty() && stack.getMin() <= array[i]) {
			int temp;
			stack.Pop(temp);
		}

		if (stack.isEmpty()) {
			result[i] = -1;
		}
		else {
			result[i] = stack.getMin();
		}

		stack.Push(array[i]);
	}

	for (int i = 0; i < size; i++) {
		array[i] = result[i];
	}

}


int main() {

	int size;
	cout << "Enter the size of the stack: ";
	cin >> size;
	Stack stack(size);
	while (true) {
		Menu();
		int choice = 0;
		cin >> choice;

		if (choice == 6) {
			break;
		}
		else if (choice == 1) {
			int n;
			cout << "\nEnter the Number: ";
			cin >> n;
			stack.Push(n);
			cout << "\nSuccessfully Pushed " << n << endl;
		}
		else if (choice == 2) {
			int n;
			stack.Pop(n);
			cout << "\nSuccessfully Popped " << n << endl;
		}
		else if (choice == 3) {
			cout << "\nSize: " << stack.Size();
		}
		else if (choice == 4) {
			cout << "\nSmallest: " << stack.getMin();
		}
		else if (choice == 5) {
			int* array = new int[size];

			for (int i = 0; i < size; i++) {
				cout << "\nEnter the Number for Array " << i+1 << ": ";		
			
				cin >> array[i];
			}

			GreaterNextElement(array, size);

			for (int i = 0; i < size; i++) {
				cout << "Array " << i << " is " << array[i] << endl;
			}
		}
		else {
			cout << "\nInvalid Input\n";
			cout << "\nTry Again";
		}
	}


	cout << "\nGoodBye!\n";
	cout << endl << endl;
	return 0;
}
