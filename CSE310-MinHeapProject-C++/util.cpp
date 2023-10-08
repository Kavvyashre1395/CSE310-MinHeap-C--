#include <iostream>
#include "util.h"
#include "heap.h"
#include <fstream>
#include <climits>

#pragma warning (disable : 4996)

using std::cout;
using std::cin;

// Initialize a basic HEAP object with size 0 and capacity 0
//HEAP heap = HEAP(0,0);
// set this to NULL
HEAP* heap = NULL;

// Initialize the file input stream
FILE* file;

// Function to organize what to execute based on input
char cases(char x)
{
	// Switch case to direct the program based on the user input
	switch (x)
	{
		// list of input variables
		int f; // flag
		int i; // index
		int k; // key
		int n; // number of nodes
		int v; // value
		int count; // count of elements in HEAPinput.txt
		int print; // print value from those functions
		int temp; // utility integer

	// Case C calls the initialize function with capacity n
	case 'C':
	case 'c':

		// Cin value n
		cin >> n;

		// If an invalid input is given, clear the cin and inform the user that there's been an invalid command
		if (cin.fail())
		{
			cout << "\nInvalid Command\n";
			cin.clear();
		}

		// Otherwise, take the input value n
		else
		{
			cout << "COMMAND: C ";
			cout << n << ".\n";

			// Set the heap object to the value initialized in the Initialize function with capacity n
			heap = Initialize(heap, n);
		}
		break;

	// Case R reads the file HEAPinput.txt and reads it into BuildHeap function
	case 'R':
	case 'r':

		// Set the default count of elements in the file to 0
		count = 0;

		cout << "COMMAND: R.\n";

		// Open up the file using the input stream
		file = fopen("HEAPinput.txt", "r");
		//file.open("HEAPinput.txt");


		// If the file is empty or non-existent, do not read further into the file
		if (not file)
		{
			cout << "There was a problem opening file HEAPinput.txt for reading.\n";
			break;
		}

		// Read the first value of the file into a variable count
		//file >> count;
		fscanf(file, "%d", &count);

		// If the heap capacity is 0, wait until the HEAP is initialized
		if (heap == NULL) {
			cout << "Sorry!!! It cannot be done. Please intialize the heap first.\n";
		}

		// If the number of values in the file is higher than the capacity, wait until the capacity of the HEAP is increased
		else if (count > heap->capacity) {
			cout << "Sorry!!! It cannot be done. Please increase the capacity of heap first.\n";
		}

		// If nothing goes wrong, begin writing all the values into the ELEMENT array and send that array into the BuildHeap function
		else
		{
			// Initialize a temporary ELEMENT array pointer inputs
			ELEMENT* inputs;
			inputs = new ELEMENT[count];

			// Adjust the heap.size to the valid count values
			heap->size = count;

			// boolean value for if the file has the right amount of items
			bool valid = true;

			// Read the values from the file into the inputs array
			for (int i = 0; i < count; i++)
			{
				// If the file runs out of values to read before the end of the loop, the input is not valid
				if (feof(file) != 0)
				{
					// Set valid to false to indicate the file was not sucessfully read
					valid = false;

					break;
				}
				//file >> inputs[i].key;
				fscanf(file, "%d", &inputs[i].key);
			}

			// If the file was successfully read, call BuildHeap
			if (valid)
			{
				// Call the Build Heap function with the inputs array and count values
				BuildHeap(heap->H, inputs, count, heap->capacity);

			}
			// Otherwise, don't do anything
			else
			{
				*heap = HEAP(0, heap->capacity);
				cout << "Sorry!!! It cannot be done. The number of elements in file is less than as specified in the beginning of file.\n";
			}

			// Free the memory allocated to the temporary ELEMENT array
			//delete[] inputs;
		}

		break;

	// Case W writes out the current value of the HEAP object
	case 'W':
	case 'w':

		cout << "COMMAND: W.\n";

		// If the HEAP is initialized, execute printHeap
		if (heap != NULL)
		{

			// Call printHeap function
			printHeap(heap->H, heap->capacity, heap->size);
		}

		// Otherwise, wait for the HEAP object to be initialized
		else
		{
			cout << "Sorry!!! It cannot be done. Please intialize the heap first.\n";
		}
		break;

	// Case I inserts a value k into the HEAP with flag f determining whether to print the HEAP or not
	case 'I':
	case 'i':

		// Cin values f and k
		cin >> f;
		cin >> k;

		// If an invalid input is given, clear the cin and inform the user that there's been an invalid command
		if (cin.fail())
		{
			cout << "Invalid Command\n";
			cin.clear();
		}

		// Otherwise take the input values f and k
		else
		{
			cout << "COMMAND: I ";
			cout << f << " ";
			cout << k << ".\n";

			// If the heap has been initialized, call Insert and set the HEAP capacity to the returned value
			if (heap != NULL)
			{
				// If the flag is one, carry out the Insert function without printing anything
				if (f == 1)
				{

					// Call Insert, which will return the new capacity value based on the current capacity and size
					heap->capacity = Insert(heap->H, heap->size, heap->capacity, f, k);
					
					// Increment the heap size by 1 since 1 value has been added to the HEAP
					heap->size = heap->size + 1;
				}

				// If the flag is two, print the before and after HEAP values
				else if (f == 2)
				{
					// Print out the value of the HEAP before the operation
					printHeap(heap->H, heap->capacity, heap->size);

					// Call Insert, which will return the new capacity value based on the current capacity and size
					heap->capacity = Insert(heap->H, heap->size, heap->capacity, f, k);

					// Increment the heap size by 1 since 1 value has been added to the HEAP
					heap->size = heap->size + 1;

					// Print out the value of the HEAP after the operation
					printHeap(heap->H, heap->capacity, heap->size);
				}

				// Handling invalid flag inputs
				else
				{
					cout << "This is not a valid flag value. This operation cannot be completed.\n";
				}
				
			}
			// Otherwise, wait for the HEAP object to be initialized
			else
			{
				cout << "Sorry!!! It cannot be done. Please intialize the heap first.\n";
			}
		}
		break;

	// Case D deletes the minimum value of HEAP and takes flag f which determines whethere to print the HEAP or not
	case 'D':
	case 'd':

		// Cin value f
		cin >> f;

		// If an invalid input is given, clear the cin and inform the user that there's been an invalid command
		if (cin.fail())
		{
			cout << "Invalid Command\n";
			cin.clear();
		}

		// Otherwise, take input value f
		else
		{
			cout << "COMMAND: D ";
			cout << f << ".\n";

			// If the HEAP has been initialized and elements are in the HEAP
			if (heap != NULL)
			{

				// If heap is empty, do not execute DeleteMin
				if (heap->size == 0)
				{
					cout << "There are no elements in heap to delete.\n";
				}

				// Otheriwse, execute the DeleteMin function
				else
				{

					// If the flag is one, carry out the DeleteMin function without printing anything
					if (f == 1)
					{
						// Call DeleteMin and print out the value that is deleted from the HEAP object
						cout << DeleteMin(heap->H, heap->size, heap->capacity, f) << "\n";

						// Decrement the heap size by 1 since 1 ELEMENT is removed
						heap->size = heap->size - 1;
					}

					// If the flag is two, print the before and after HEAP values
					else if (f == 2)
					{
						// Print out the value of the HEAP before the operation
						printHeap(heap->H, heap->capacity, heap->size);

						// Call DeleteMin and print out the value that is deleted from the HEAP object
						print = DeleteMin(heap->H, heap->size, heap->capacity, f);

						// Decrement the heap size by 1 since 1 ELEMENT is removed
						heap->size = heap->size - 1;

						// Print out the value of the HEAP after the operation
						printHeap(heap->H, heap->capacity, heap->size);

						cout << print << "\n";
					}

					// Handling invalid flag inputs
					else
					{
						cout << "This is not a valid flag value. This operation cannot be completed.\n";
					}
					
				}

			}

			// Otherwise, wait for the HEAP to be initialized and ELEMENTs to be placed in the HEAP
			else
			{
				cout << "Sorry!!! It cannot be done. Please initialize the heap first and put the elements into it.\n";
			}
		}
		break;

	// Case K decreases the key of the ELEMENT array at index i to value v and with flag f determining whether to print HEAP or not
	case 'K':
	case 'k':

		// Cin values f, i, and v
		cin >> f;
		cin >> i;
		cin >> v;

		// If an invalid input is given, clear the cin and inform the user that there's been an invalid command
		if (cin.fail())
		{
			cout << "Invalid Command\n";
			cin.clear();
		}
		else
		{
			cout << "COMMAND: K ";
			cout << f << " ";
			cout << i << " ";
			cout << v << ".\n";

			// If the HEAP has been initialized and elements are in the HEAP
			if (heap != NULL)
			{
				// If there are enough elements within HEAP, call DecreaseKey at index i
				if (heap->size >= i && i >= 1)
				{
					// If v is lower than or equal to the value at index i
					if (v <= heap->H[i].key)
					{

						// If the flag is one, carry out the DecreaseKey function without printing anything
						if (f == 1) 
						{
							// Call the DecreaseKey function
							DecreaseKey(heap->H, heap->capacity, heap->size, f, i, v);
						}

						// If the flag is two, print the before and after HEAP values
						else if(f == 2)
						{
							// Print out the value of the HEAP before the operation
							printHeap(heap->H, heap->capacity, heap->size);

							// Call the DecreaseKey function
							DecreaseKey(heap->H, heap->capacity, heap->size, f, i, v);

							// Print out the value of the HEAP after the operation
							printHeap(heap->H, heap->capacity, heap->size);
						}

						// Handling invalid flag inputs
						else
						{
							cout << "This is not a valid flag value. This operation cannot be completed.\n";
						}
						
					}

					// Otherwise, wait for a smaller value
					else
					{
						cout << v << " cannot be larger than the current value in the heap at index " << i << ". Hence this operation cannot be completed.\n";
					}

				}

				// Otherwise, there are not enough elements within the HEAP
				else
				{
					cout << "There are only " << heap->size << " elements in the heap. Hence this operation cannot be completed.\n";
				}

			}
			// Otherwise, wait for the HEAP to be initialized and ELEMENTs to be placed in the HEAP
			else
			{
				cout << "Sorry!!! It cannot be done. Please initialize the heap first and put the elements into it.\n";
			}

		}
		break;

	// Case S stops the program
	case 'S':
	case 's':

		// If S is ever inputted, exit the program immediately
		cout << "COMMAND: S.\n";
		cout << "The program is going to be terminated.\n";
		//free(heap->H);
		free(heap);

		return NULL;

		// Default case includes the rest of possible inputs
	default:

		// If any other case is given, assume it is an invalid input
		cout << "Invalid Command\n";
		break;

	}
	return x;
}


