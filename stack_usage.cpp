// Stack Usage in CUTILS

#include "cutils.hpp"

int main()
{
	// initial array
	vector<int> arr({1, 2, 5, 20});

	// stack
	Stack<int> stk = Stack<int>(arr);

	// print the initial Stack
	cout << "Initial Stack" << endl;
	stk.printStack();	// 1 2 5 20

	// pop method
	cout << "\nPop Method" << endl;
	stk.pop();
	stk.printStack();	// 1 2 5

	// Push Method
	cout << "\nPush Method" << endl;
	stk.push(23);
	stk.printStack();	// 1 2 5 23

	// Insert method
	cout << "\nInsert Method" << endl;
	stk.insert(1, 21);
	stk.printStack();	// 1 21 2 5 23

	// Remove method
	cout << "\nRemove Method" << endl;
	stk.remove(2);		// 2 is the index, item in index 2 will be removed
	stk.printStack();	// 1 21 5 23

	// print the updated array
	cout << "\nUpdated Array: ";

	for (int i = 0; i < stk.arr.size(); i++)
		cout << stk.arr[i] << " ";

	cout << endl;
	return 0;
}
