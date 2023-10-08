#ifndef HEAP1
#define HEAP1

// Declare the ELEMENT struct

struct ELEMENT {
	int key;
};

// Declare the HEAP class

class HEAP
{

// Declare all the variables of the HEAP class
public:
	int size;
	int capacity;
	ELEMENT* H;

	HEAP(int size, int num); // constructor
	HEAP* Initialize(HEAP* existing, int n);
	void printHeap (ELEMENT* H, int capacity, int size);
	void BuildHeap(ELEMENT* heap, int A[], int capacity, int n);
	int Insert(ELEMENT* H, int size, int capacity, int flag, int k);
	int DeleteMin(ELEMENT* H, int n, int capacity, int flag);
	void DecreaseKey(ELEMENT* H, int capacity, int size, int flag, int index, int value);
	void swapElement(ELEMENT* first, ELEMENT* second);
	int parent(int i);
	int left(int i);
	int right(int i);
	void MinHeapify(ELEMENT* heap, int capacity, int size, int i);
};

#endif