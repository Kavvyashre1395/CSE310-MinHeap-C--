#include <iostream>
#include "heap.h"
#include <limits>
#include <climits>

using std::cout;
using std::cin;
using std::endl;


HEAP::HEAP(int sizer, int num)
{
	size = sizer;
	capacity = num;
	this->H = (ELEMENT*)malloc(num*sizeof(ELEMENT));
	//H = new ELEMENT[num];
}

// Utility function to swap ELEMENTs that is used in the Min-Heapify function

void swapElement(ELEMENT* first, ELEMENT* second)
{
	// Save the first value in temp
	ELEMENT temp = *first;

	// Swap the values of first and second using the saved value in temp
	*first = *second;
	*second = temp;
}

// Utility functions that determine the parent, left, and right nodes in relationship to node i

int parent(int i) { return i / 2; }

int left(int i) { return (2 * i); }

int right(int i) { return (2 * i + 1); }

// Utility Min-Heapify Function
void MinHeapify(ELEMENT* heap, int capacity, int size, int i)
{
	int l = left(i); // l = 2i
	int r = right(i); // r = 2i+1
	int smallest = i; // set the default smallest value to i

	// if l's key is smaller than i's key, set smallest to l
	if (l <= size && heap[l].key < heap[i].key)
		smallest = l;

	// if r's key is smaller than i's and l's key, set smallest to r
	if (r <= size && heap[r].key < heap[smallest].key)
		smallest = r;

	// If l's or r's key were smaller than i, carry out the swapElement and MinHeapify
	if (smallest != i)
	{
		swapElement(&heap[i], &heap[smallest]);
		MinHeapify(heap, capacity, size, smallest);
	}
}

// Function to initialize the HEAP
HEAP* Initialize(HEAP* existing, int n)
{

	if (existing != NULL) 
	{
		/*
		if (existing->H != NULL)
		{
			free(existing->H);
		}
		*/
		//free(existing->H);
		free(existing);

		HEAP* heap = (HEAP*)malloc(sizeof(HEAP));

		*heap = HEAP(0, n); 

		return heap;
	}
	else 
	{
		// Initialization of the HEAP object
		HEAP* heap = (HEAP*)malloc(sizeof(HEAP));

		// Calling the constructor to create the HEAP with a default size of 0 and a capacity n
		*heap = HEAP(0, n);

		return heap;
	}

};

// Function to print the HEAP values
void printHeap(ELEMENT* H, int capacity, int size)
{
	// O(n) printing out the heap values
	cout << "The capacity is " << capacity << ".\n";
	cout << "Size is " << size << ".\n";

	// Iterating through the ELEMENT array to print out every value of the heap
	for (int i = 1; i <= size; i++) {
		cout << H[i].key << "\n";
	};

};

// Function to build the HEAP
void BuildHeap(ELEMENT* heap, ELEMENT* A, int n, int capacity)
{
	// Creation of the heap starting at index 1 so as not to confuse the Min-Heapify function
	for (int i = 1; i <= capacity; i++)
	{
		if (i <= n)
		{
			// Copying ELEMENT array A into the HEAP ELEMENT array H
			heap[i].key = A[i - 1].key;
		}
		else
		{
			// Replacing all the unused elements with the max unsigned integer so as to avoid complications with the Min-Heapify function
			heap[i].key = INT_MAX;
		}

	}

	// Calling Min-Heapify to organize the values inputted
	for (int i = n / 2; i >= 1; i--)
	{
		MinHeapify(heap, capacity, n, i);
	}

};


// Function to insert a value into the HEAP
int Insert(ELEMENT* H, int size, int capacity, int flag, int k)
{
	int num = capacity;

	// If the size of the desired final HEAP should be more than the initialized capacity, determine the new size of the HEAP
	if (size + 1 > capacity)
	{
		num = 1;

		// Multiply num by 2 until it is larger than the current capacity
		while (num <= capacity)
		{
			num = num * 2;
		}
	}

	// Using a temporary pointer to carry out the Insert function
	ELEMENT* H1 = H;


	// Insert the k value into the HEAP
	H1[size + 1].key = k;

	// Make sure the size is more than 0 to execute the rest of this code
	if (size > 0)
	{
		// Fill the remaining unused values of the ELEMENT array with the max unsigned integer
		for (int i = size + 2; i <= num; i++) {
			H1[i].key = INT_MAX;
		}

		// Carry out the MinHeapify function on the ELEMENT array
		for (int i = num / 2; i >= 1; i--)
		{
			MinHeapify(H1, capacity, num, i);
		}
	}

	// Return the updated capacity value, either num or capacity
	if (num >= capacity)
	{
		return num;
	}
	else
	{
		return capacity;
	}
};

// Function to delete the minimum value from the HEAP
int DeleteMin(ELEMENT* H, int n, int capacity, int flag) {

	// Save the minimum value of the HEAP
	int temp = H[1].key;


	// Overwrite the first value of HEAP with the last value of HEAP
	H[1].key = H[n].key;

	// Call MinHeapify on the ELEMENT array
	for (int i = n / 2; i >= 1; i--)
	{
		MinHeapify(H, capacity, n, i);
	}

	// Return the minimum value that was deleted from the HEAP
	return temp;
};

// Function to decrease the key of a value in the HEAP
void DecreaseKey(ELEMENT* H, int capacity, int size, int flag, int index, int value) {

	// Change the key value at index to value
	H[index].key = value;

	// Call MinHeapify on the ELEMENT array
	for (int i = size / 2; i >= 1; i--)
	{
		MinHeapify(H, capacity, size, i);
	}

};



