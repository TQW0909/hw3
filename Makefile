CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------

llrec-test: llrec-test.cpp llrec.o
	$(CXX) $(CXXFLAGS) llrec-test.cpp llrec.o -o llrec-test

llrec.o: llrec.cpp llrec.h
	$(CXX) $(CXXFLAGS) -c llrec.cpp -o llrec.o

clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 