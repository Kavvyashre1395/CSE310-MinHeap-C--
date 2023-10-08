#include <iostream>
#include "util.h"

using std::cout;
using std::cin;

// list of functions for forward declaration
char cases(char x);

// main function
int main()
{
	char input = '\0'; // default value of the input
	char breakout = 'A';

	while (breakout) {

		// Info text directing the user on the possible inputs
		/*cout << "\nWhat would you like to do?\n\n";
		cout << "\t C n : creates an emtpy heap with n nodes\n";
		cout << "\t R : reads in array A from HEAPinput.txt, and builds a min-heap based on A\n";
		cout << "\t W : writes the current heap information to the screen\n";
		cout << "\t I f k : inserts an element into the array with key k and corresponding flag f\n";
		cout << "\t D f : deletes the the minimum element of the heap with flag set to f\n";
		cout << "\t K f i v: decreases the key of index i to v with corresponding flag set to f\n";
		cout << "\nIf you want to quit the program at anytime, input S\n";*/

		cin >> input; // take the input
		breakout = cases(input); // call the input handling function

	}
	return 0;
}

