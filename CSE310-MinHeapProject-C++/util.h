#include "heap.h"

// All the functions to be used in util.cpp

char cases(char x);
void swapElement(ELEMENT* first, ELEMENT* second);
int parent(int i);
int left(int i);
int right(int i);
void MinHeapify(ELEMENT* heap, int capacity, int size, int i);
HEAP* Initialize(HEAP* existing, int n);
void BuildHeap(ELEMENT* heap, ELEMENT* A, int capacity, int n);
int Insert(ELEMENT* H, int size, int capacity, int flag, int k);
int DeleteMin(ELEMENT* H, int n, int capacity, int flag);
void DecreaseKey(ELEMENT* H, int capacity, int size, int flag, int index, int value);
void printHeap(ELEMENT* H, int capacity, int size);
