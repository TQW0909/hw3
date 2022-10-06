#include <iostream>
#include <fstream>
#include <functional>
#include "llrec.h"
using namespace std;

/**
 * Reads integers (separated by whitespace) from a file
 * into a linked list.
 *
 * @param[in] filename
 *  The name of the file containing the data to read
 * @return
 *  Pointer to the linked list (or NULL if empty or the
 *  file is invalid)
 */
Node* readList(const char* filename);

/**
 * Prints the integers in a linked list pointed to
 * by head.
 */
void print(Node* head);

/**
 * Deallocates the linked list nodes
 */
void dealloc(Node* head);


Node* readList(const char* filename)
{
    Node* h = NULL;
    ifstream ifile(filename);
    int v;
    if( ! (ifile >> v) ) return h;
    h = new Node(v, NULL);
    Node *t = h;
    while ( ifile >> v ) {
        t->next = new Node(v, NULL);
        t = t->next;
    }
    return h;
}

void print(Node* head)
{
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void dealloc(Node* head)
{
    Node* temp;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

// -----------------------------------------------
//   Add any helper functions or
//   function object struct declarations
// -----------------------------------------------

struct isFiltered
{
	bool operator()(int val)
	{
		return val % 2 == 1;
	}
};




int main(int argc, char* argv[])
{
    if(argc < 2) {
        cout << "Please provide an input file" << endl;
        return 1;
    }

    // -----------------------------------------------
    // Feel free to update any code below this point
    // -----------------------------------------------
	Node* head = readList(argv[1]);
	cout << "Original list: ";
	print(head);

	// Test out your linked list code

    // -----------------------------------------------
	// Split/pivot test 1 (Test using input files: llrec-test<1-5>.in)
    // -----------------------------------------------
    cout << endl << endl << "PIVOT TEST: " << endl;
	Node* smaller = nullptr;
	Node* larger = nullptr;

	int pivot = 8; // Change to any desired integer relavent for each input file

	llpivot(head, smaller, larger, pivot);

	cout << "Pivot: " << pivot << endl;
	cout << "Smaller list: ";
	print(smaller);
	cout << "Larger list: ";
	print(larger);


    // -----------------------------------------------
	// Filter test (Test using input files: llrec-test<1-5>.in)
    // -----------------------------------------------
    head = readList(argv[1]);

	cout << endl << endl << "FILTER TEST: " << endl;
	isFiltered comp;
	head = llfilter<isFiltered>(head, comp);

	cout << "NEW list: ";
	print(head);

	dealloc(head);

	return 0;
}
