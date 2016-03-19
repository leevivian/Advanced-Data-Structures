/*	Name: Vivian Lee
	Compiler: Microsoft Visual Studio Express 2015

	Description: This files contains the implmentations of each 
	function being called from the main method. readData prompts
	the user for input. While there are values from the input,
	these values are pushed into the vector called intVector. 
	The vector gets sorted through a general selection sort algorithm
	at the selectionSort method. The inital, unsorted vector as well
	as the sorted vector get printed via the printVector method.*/

#include "Header.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

/* readData receives input from the user in the form of a string. While
there is a stream, these input values are placed in intVector. */
void readData(vector<int>& intVector) {
	int input;
	string line;

	cout << "Enter integers separated by spaces: " << endl;
	getline(cin, line);
	istringstream stream(line);
	while (stream >> input) {
		intVector.push_back(input);
	}
	cout << "Initial Vector: " << endl;
}

/* Prints out the contents of a vector when called from the main method. */
void printVector(const vector<int>& intVector) {

	for (int i = 0; i < intVector.size(); i++) {
		cout << intVector[i] << " ";
	}
	cout << endl;
}

/* Sorts the contents of the vector from smallest values to largest values 
by going through the indices and comparing the elements. */
void selectionSort(vector<int>& intVector) {
	int i, j, minIndex;
	int vectorSize = intVector.size();

	for (i = 0; i < vectorSize - 1; i++) {
		minIndex = i;
		for (j = i + 1; j < vectorSize; j++) {
			if (intVector[j] < intVector[minIndex]) {
				minIndex = j;
			}
		}
		if (minIndex != i) {
			swap(intVector[i], intVector[minIndex]);
		}
	}
	cout << "Sorted Vector: " << endl;
}
