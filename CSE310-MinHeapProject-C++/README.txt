------------------------------------------
Project Title: MIN-HEAP Project
Author: Kavyasree Vayalpati, ASU student #1224534701
------------------------------------------

------------
Description: 
------------

This project implements the data structure MIN-HEAP with various functionalities:
1. Initialization of HEAP, 
2. Creation of HEAP using a text file input
3. Printing of a heap
4. Insert and deletion of elements in the HEAP
5. Modification of values within the HEAP.

----------------------
Overview of the Files:
----------------------

My Min-Heap project consists of 7 files.

1. Makefile
	- Purpose: To compile all the cpp and h files using one simple command.

2. README.txt
	- Purpose: To explain all files, functions, and variables clearly and document all the ideas behind the program.

3. main.cpp
	- Purpose: Main function that executes the start of the code including the while loop that prompts the user for input and calls the function that handles the input.
	- Functions: main

4. heap.h
	- Purpose: Declares the class HEAP, all of its member variables, as well as the constructor for HEAP.

5. heap.cpp
	- Purpose: Defines the default constructor, completes the body of the constructor, and implements the HEAP class functions.
	- Functions: swapElement, MinHeapify, Initialize, printHeap, BuildHeap, Insert, DeleteMin, DecreaseKey, HEAP Constructor

6. util.cpp
	- Purpose: Contains much of the implementation for the program including the input handler that is called based on the user input.
	- Functions: cases

7. util.h
	- Purpose: Declares all the functions to be used in util.cpp, such as MinHeapify, and the various other HEAP functions

-----------------------
How to run the project:
-----------------------

To run the project, execute the Makefile in gcc to compile all the files by typing the make command. Then, to run the program itself, enter ./run in the console

-----------------------
How to use the project:
-----------------------

To use the project, run the project and follow the instructions that print out on the screen in terms of the necessary inputs to execute your desired commands on the MIN-HEAP.

To initialize a HEAP, enter in C n, where n is the desired capacity of the HEAP object.

To build a HEAP from the input file, enter in R.

To print out the current HEAP object, including capacity, size, and the ELEMENTs, enter in W.

To insert an ELEMENT in the HEAP, enter in I f k, where f is the flag that determines the print state of the function, and k is the key of the ELEMENT being added into the array.

To delete the minimum ELEMENT from the HEAP, enter in D f, where f is the flag that determines the print state of the function.

To decrease the key of an ELEMENT in the heap, enter in K f i v, where f is the flag that determines the print state of the function, i is the index of the value to be decreased, and v is the value to change the key to.
