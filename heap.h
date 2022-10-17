#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below

	void trickleUp(int loc);
	void heapify(int loc);

	std::vector<T> myHeap;
	int _ary; // Stores the -ary of the heap
	PComparator compare; // Stores the comparator that determines whether the heap is min or max

};

// Add implementation of member functions here

template <typename T, typename Comparator>
void Heap<T,Comparator>::trickleUp(int loc)
{
	int parent = (loc - 1) / _ary;
  
	while (parent >= 0 && compare(myHeap[loc], myHeap[parent]))
	{
		// Swapping values
    T temp = myHeap[loc];
    myHeap[loc] = myHeap[parent];
    myHeap[parent] = temp;

		// Updating parent index
    loc = parent;
    parent = (loc - 1) / _ary;
	}
}


template <typename T, typename Comparator>
void Heap<T,Comparator>::heapify(int loc) // aka trickle down
{
	// Checking if loc is a leaf node
	if(loc * _ary + 1 > (int)size()) 
	{
		return;
	}

	int priorityChild = loc * _ary + 1; // Left child
	int child = priorityChild;

	// Checks every existing child node and finds the child index with highest priority
	while (child + 1 <= (int)size())
	{
		child++;
		
		if (compare(myHeap[child], myHeap[priorityChild]))
		{
			priorityChild = child;
		}
	}

	// Checking if data at priority child has greater priority than data at loc
	if (compare(myHeap[priorityChild], myHeap[loc]))
	{
		// Swapping values
		T temp = myHeap[loc];
		myHeap[loc] = myHeap[priorityChild];
		myHeap[priorityChild] = temp;

		// Recursive call
		heapify(priorityChild);
	}
}

// Constructor
template <typename T, typename Comparator>
Heap<T,Comparator>::Heap(int m, Comparator c) :
_ary(m), 
compare(c)
{
}


// Destructor
template <typename T, typename Comparator>
Heap<T,Comparator>::~Heap()
{
}


// Pushing item into heap
template <typename T, typename Comparator>
void Heap<T,Comparator>::push(const T& item)
{
	myHeap.push_back(item);
	trickleUp(size() - 1); // Maintainning heap property
}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
		throw std::underflow_error("Error: Heap is empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
	return myHeap.front();
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
		throw std::underflow_error("Error: Heap is empty");

  }
	myHeap[0] = myHeap.back(); // Moving last item into index 0
	myHeap.pop_back();// Deleting last item
	heapify(0); // Maintainning heap property
}


template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
	return myHeap.empty();
}


template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
	return myHeap.size();
}


#endif

