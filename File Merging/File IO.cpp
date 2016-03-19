/*	Name: Vivian Lee
	Compiler: Microsoft Visual Studio Express 2015

	Description: This program obtains the name of two text files containing integers
	in non-decreasing order from the user and merges them into a third file where
	the numbers remain in their sorted order. The name of the merged file is printed
	to the user and exists in the same directory.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function that merges the two files that the user chose. The files are iteratorated
// through and its contents are stored one at a time by comparing the values within
// temporary variables. The merged file is returned and the file name is printed
// to the user.
string merge_files(string file1, string file2) {

	ifstream firstFile(file1);
	ifstream secondFile(file2);
	ofstream mergedFile("Merged File.txt", ofstream::out);

	if (firstFile.is_open()) {
		if (secondFile.is_open()) {

			// Uses seekg to get the end of both the first file and the second file.
			firstFile.seekg(0, ios::end);
			int eoFile1 = (int)firstFile.tellg();
			firstFile.seekg(0, ios::beg);
			
			secondFile.seekg(0, ios::end);
			int eoFile2 = (int)secondFile.tellg();
			secondFile.seekg(0, ios::beg);

			int i = 0;
			int j = 0; 
			int k = 0; 

			// Iterates through the files and loads the file's integers into two temporary
			// variables. The temp variables are compared to determine when they should
			// be loaded into the merged file. 
			while ((i < eoFile1) && (j < eoFile2)) {

				firstFile.seekg(i, ios::beg);
				secondFile.seekg(j, ios::beg); 
				mergedFile.seekp(k, ios::beg); 

				int temp1 = (int)firstFile.get(); 
				int temp2 = (int)secondFile.get(); 
				if (temp1 < temp2) {
					mergedFile.put((char)temp1);
					i++;
					k++;
				} else {
					mergedFile.put((char)temp2);
					j++;
					k++;
				}
			} 
			// If a file still has numbers left, the rest will be 
			// added to the end of the merged file.
			while (i < eoFile1) {	
				firstFile.seekg(i, ios::beg); 
				mergedFile.seekp(k, ios::beg);
				mergedFile.put(firstFile.get());
				i++;
				k++;
			} 
			while (j < eoFile2) { 
				secondFile.seekg(j, ios::beg); 
				mergedFile.seekp(k, ios::beg);
				mergedFile.put(secondFile.get());
				j++;
				k++;
			}
		} 
	}

	firstFile.close();
	secondFile.close();
	mergedFile.close();
	return "Merged File.txt";
}


// Function that checks to see if the user's named file exists or not.
// Returns a value to the main.
inline bool fileExists(const string& file) {
	ifstream f(file.c_str());
	if (f.good()) {
		f.close();
		return true;
	} else {
		f.close();
		return false;
	}
}

string merge_files(string, string);
bool fileExists(const string & s);
bool replay = true;
string play;

// Prompts user to type in the name of the first and second file they would like to merge.
// If the file could not be found, the user will be prompted to try again. 
int main() {

	while (replay) {
		string firstFile, secondFile;

		cout << "Please type the name of the first file: ";

		do {
			getline(cin, firstFile);
			if (!fileExists(firstFile)) {
				cout << "\nFile cannot be found. Please try again. \nEnter the name of your first file: ";
			}
		} while (!fileExists(firstFile));

		cout << "\nPlease type the name of the second file: ";

		do {
			getline(cin, secondFile);
			if (!fileExists(secondFile)) {
				cout << "\nFile cannot be found. Please try again. \nEnter the name of your second file: ";
			}
		} while (!fileExists(secondFile));

		cout << "\nThe files have been merged. The new file has been saved as : " << merge_files(firstFile, secondFile);

		cout << "\nWould you like to play again? (y/n) " << endl;
		getline(cin, play);

		if (play == "y") {
			replay = true;
		} else {
			replay = false;
		}
	}
	return 0;
}