## HW 3

 - Name: Tingqi (Ting) Wang
 - Email: twang356@usc.edu

### Programming Problem Notes

 - How we should compile your code (`g++` command or `make` target)
	- To compile code for `llrec-test.cpp`, use `make`
	- To compile code for `stack_test.cpp`, use `g++ -g -Wall --std=c++11 stack_test.cpp -o stack_test.o`


 - Design decisions you made or other non-trivial choices for your implementation
	- There is no `stack.cpp` file because all the class implementations had to take place in the header file (due to templates).
	- 0 is a not-odd integer for the sake of the `llfilter()` function


 - Any additional tests you wrote and what files those exist in
	- `stack_test.cpp` is code to test the stack class
	- Use `llrec-test1.in`, `llrec-test2.in`, `llrec-test3.in`, `llrec-test4.in`, `llrec-test5.in` as inputs files for `llrec-test.cpp`


 - Known errors/anything to help us grade (though we will run automated tests,
knowing what features may be broken/missing may help us provide some partial credit)
	- No known Errors