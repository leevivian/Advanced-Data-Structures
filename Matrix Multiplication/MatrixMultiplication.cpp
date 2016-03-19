/*	Name: Vivian Lee
	Student ID: 913459409
	E-Mail: vlee1@mail.sfsu.edu
	Compiler: Microsoft Visual Studio Express 2015

	Description: This program computes the product of two matrices. The user is prompted 
	to enter the dimensions of two matrices, A and B. If the dimensions are not
	appropriate for matrix multiplication, the user will be asked to re-input their
	values. The user also inputs the values into the matrices. The multiplied
	result is printed to the user. */

#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

vector< vector <int> > multiply_matricies(vector< vector<int> >&, vector< vector<int> >&);

vector< vector<int > > multiply_matricies(vector< vector<int> >& A, vector< vector<int> >& B) {
	vector<vector<int> > userMatrix;

	// Resizes the resulting matrix, dependent on the user's dimension input
	userMatrix.resize(A.size());
	for (int i = 0; i < A.size(); i++) {
		userMatrix[i].resize(B[0].size());
	}

	// Matrices A and B are multipled here, the result is returned to main
	for (int i = 0; i < userMatrix.size(); i++) {           
		for (int j = 0; j < userMatrix[0].size(); j++) {      
			for (int k = 0; k < A[0].size(); k++) {   
				userMatrix[i][j] += A[i][k] * B[k][j];         
			}                                        
		}
	}
	return userMatrix;
}

// The main function prompts the user for the dimensions of Matrix A and Matrix B. If the columns
// of Matrix A are equal to the rows of Matrix B, the matrices are resized, and the user 
// is prompted to enter the contents of the matrices. The fucntion  multiply_matricies is
// then called and returns the resulting multiplied matrices, which is printed.
int main() {

	bool running = true;
	string replay;

	while (running) {
		int rowsA, columnsA, rowsB, columnsB;
		vector<vector<int> > matrixA, matrixB, userMatrix;

		cout << " --- Dimensions of Matrix A --- \n" << "Enter the Number of Rows: ";
		cin >> rowsA;
		cout << "Enter the Number of Columns: ";
		cin >> columnsA;

		cout << "\n --- Dimensions of Matrix B --- \n" << "Enter the Number of Rows: ";
		cin >> rowsB;
		cout << "Enter the Number of Columns : ";
		cin >> columnsB;

		if (columnsA == rowsB) {

			matrixA.resize(rowsA);
			for (int i = 0; i < rowsA; i++) {
				matrixA[i].resize(columnsA);
			}

			matrixB.resize(rowsB);
			for (int i = 0; i < rowsB; i++) {
				matrixB[i].resize(columnsB);
			}

			cout << "\nInput the Entries (separated by spaces) for Matrix A: " << endl;
			for (int i = 0; i < rowsA; i++) {
				for (int j = 0; j < columnsA; j++) {
					cin >> matrixA[i][j];
				}
				cout << endl;
			}

			cout << "\nInput the Entries (separated by spaces) for Matrix B: " << endl;
			for (int i = 0; i < rowsB; i++) {
				for (int j = 0; j < columnsB; j++) {
					cin >> matrixB[i][j];
				}
				cout << endl;
			}

			userMatrix = multiply_matricies(matrixA, matrixB);

			cout << "\nMatrix A x  Matrix B = " << endl;
			for (int i = 0; i < userMatrix.size(); i++) {
				for (int j = 0; j < userMatrix[0].size(); j++) {
					cout << userMatrix[i][j] << " ";

				}
				cout << endl;

			}
			cout << "\nWould you like to try again? (y/n) " << endl;
			cin >> replay;

			if (replay == "y") {
				running = true;
			}
			else {
				running = false;
			}
		}
		else {
			cout << "\nMatrix dimensions must be (m x n) and (n x r) for valid multiplication." << "\nPlease try again.\n" << endl;
		}
	}
}
