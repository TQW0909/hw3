## HW 3

 - Name: Tingqi (Ting) Wang
 - Email: twang356@usc.edu

### Programming Problem Notes (Checkpoint)

 - How we should compile your code (`g++` command or `make` target)
	- To compile code for `llrec-test.cpp`, use `make`
	- To compile code for `stack_test.cpp`, use `g++ -g -Wall --std=c++11 stack_test.cpp -o stack_test`


 - Design decisions you made or other non-trivial choices for your implementation
	- There is no `stack.cpp` file because all the class implementations had to take place in the header file (due to templates).
	- 0 is a not-odd integer for the sake of the `llfilter()` function


 - Any additional tests you wrote and what files those exist in
	- `stack_test.cpp` is code to test the stack class, use `./stack_test` to run test
	- To test the `llpivot()` and `llfilter`, use `./llrec-test <inputfile>`
		- Input files: `llrec-test1.in`, `llrec-test2.in`, `llrec-test3.in`,`llrec-test4.in`, `llrec-test5.in`


 - Known errors/anything to help us grade (though we will run automated tests,
knowing what features may be broken/missing may help us provide some partial credit)
	- No known errors


### Programming Problem Notes (Heap Part)

 - How we should compile your code (`g++` command or `make` target)
	- Make sure to switch to the `heap_test` directory: `cd hw3/heap_test`
	- Use `make` to compile `heap.h`
	- Test suite provided exists in `heap_test.cpp`, use `make test` to run tests.
	- Use `make valgrind` to run valgrind.


 - Design decisions you made or other non-trivial choices for your implementation
	- I choose to use 0-base indexing when implementing my heap.


 - Any additional tests you wrote and what files those exist in
	- None


 - Known errors/anything to help us grade (though we will run automated tests,
knowing what features may be broken/missing may help us provide some partial credit)
	- No known errors



### Programming Problem Notes (Logic Simulator Part)

 - How we should compile your code (`g++` command or `make` target)
	- Make sure to switch to the `logicsim` directory: `cd hw3/heap_test`
	- Use `make` to compile program.
	- Use `./logicsim <circuit>.txt` to run program.
		- `single_and.txt`, `single_or.txt`, `single_not.txt`, and `exclusive_or.txt`
	- Use `./logicsim > <filename>.uml` and `java -jar plantuml.jar <filename>.uml` to create a timing diagram.
		- Diagram will be in `<filename>.png` file.


 - Design decisions you made or other non-trivial choices for your implementation
	- None


 - Any additional tests you wrote and what files those exist in
	- None


 - Known errors/anything to help us grade (though we will run automated tests,
knowing what features may be broken/missing may help us provide some partial credit)
	- No known errors