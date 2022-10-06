#include "stack.h"
#include <iostream>

using namespace std;

int main()
{
	// Testing constructor
	Stack<int> testing;

	// checking empty()
	if (testing.empty())
	{
		cout << "Stack is empty" << endl;
	}
	
	// Populating stack
	cout << "Populating stack ..." << endl;
	for (int i = 0; i < 10; i++)
	{
		testing.push(i);
		cout << testing.top() << endl;
	}

	// Checking if empty and size
	if (!testing.empty())
	{
		cout << "Stack is not empty" << endl;
		cout << "Stack size: " << testing.size() << endl;
	}

	// Clearing stack using pop and printing each deleted value
	cout << "Clearing stack ..." << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << testing.top() << endl;
		testing.pop();
	}

	// Check if set is empty
	if (testing.empty())
	{
		cout << "Stack is empty" << endl;
	}

	// Testing for empty stack and throwing exceptions
	try
	{
		testing.pop();
	}
	catch (underflow_error& e)
	{
		cout << e.what() << endl;
	}
	
	try
	{
		int temp = testing.top();	
	}
	catch (underflow_error& e)
	{
		cout << e.what() << endl;
	}


	return 0;
}