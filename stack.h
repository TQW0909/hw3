#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T> // Private because don't want the user to have access to std::vector functions
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
private:
    std::vector<T> myStack;
};


template <typename T>
Stack<T>::Stack() : std::vector<T>()

{
	
}

template <typename T>
Stack<T>::~Stack()
{

}

// Returns if stack is empty
template <typename T>
bool Stack<T>::empty() const
{
	return myStack.std::vector<T>::empty();
}

// Returns size of stack
template <typename T>
size_t Stack<T>::size() const
{
	return myStack.std::vector<T>::size();
}

// Adds item into stack
template <typename T>
void Stack<T>::push(const T& item)
{
	myStack.std::vector<T>::push_back(item);
}

// Remove item from stack
template <typename T>
void Stack<T>::pop()  // throws std::underflow_error if empty
{
	if (empty())
	{
		throw std::underflow_error("pop() Error: Stack is empty");
	}

	myStack.std::vector<T>::pop_back();
}

// Returns top value in stack
template <typename T>
const T& Stack<T>::top() const // throws std::underflow_error if empty
{
	if (empty())
	{
		throw std::underflow_error("top() Error: Stack is empty");
	}

	return myStack.std::vector<T>::back();
}

#endif