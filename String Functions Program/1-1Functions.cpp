/*	Name: Vivian Lee
	Compiler: Microsoft Visual Studio Express 2015 
	
	Description: This file implements the member functions of
	each class. Each method is initially called from within
	the main method in the driver file, HW1-1Main.cpp. The 
	user's input is taken and is operated on to obtain 
	its traits specified by the assignment instructions. */

#include "Header.h"

/* getLeastFreqLetter obtains the user's least frequent letter 
	and its frequency. 
	It takes each letter from the user's input and turns them all 
	into lowercase letters. Then, each letter's frequency is counted 
	by inputting them in an array. By comparing the elements within
	each index of the array, the least frequent letter and its frequency
	is found and printed. */
void getLeastFreqLetter(string input) {
	int letterFreq[26] = { 0 };
	int counter;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] >= 'A' && input[i] <= 'Z') {
			input[i] = tolower(input[i]);
		}
	
		if (input[i] >= 'a' && input[i] <= 'z') {
			letterFreq[input[i] - 'a']++;
		}
	}

	int minIndex = 0;
	for (int i = 1; i < 26; i++) {
		
		if (letterFreq[minIndex] > letterFreq[i] && letterFreq[i] != 0) {
			minIndex = i;
		} if (letterFreq[minIndex] == 0) {
			minIndex++;
		}
	}

	cout << "\nThe Least Frequent Letter is: " << (char)(minIndex + 'A') << 
		"\nIts frequency is: " << letterFreq[minIndex] << endl;
}

/* This global struct contains public variables necessary for the function
	countWordFreq.*/
struct countWord {
	string word;
	int count;
};

/* countWordFreq uses an array wordFreq. Each char is checked for word
	delimiters and placed into wordFreq. If a delimiter does not exist,
	the word is established into wordFreq and by using a temporary string,
	which also aids in comparing words in order to update each unique
	word's frequency. Each index within the array is then read and prints 
	unique words and their respective frequencies. */
countWord *countWordFreq(string input){
	countWord *wordFreq = new countWord[100];
	// Clears the array wordFreq
	for (int i = 0; i < 100; i++) {
		wordFreq[i].word = "";
		wordFreq[i].count = 0;
	}

	int wordIndex = 0;
	int arrIndex = 0;
	string temp = "";
	bool exists = true;

	for (int i = 0; i <= input.length(); i++) {
		if (input[i] >= 'A' && input[i] <= 'Z') {
			input[i] = tolower(input[i]);
		}

		if (input[i] == ' ' || input[i] == '\t' ||  input[i] == '.' || input[i] == ',' || input[i] == ';' || input[i] == '!' || input[i] == '?' || i == input.length()) {
			for (int minIndex = 0; minIndex <= arrIndex; minIndex++) {
				// If the word does not exist yet, its frequency (count) is updated and 
				// the word gets established.
				if (temp.compare(wordFreq[minIndex].word) == 0) {
					wordFreq[minIndex].count++;
					temp.clear();
					exists = true;
					break;
				} else {
					exists = false;
				}
			}
			// If the word already exists, its frequency (count) is updated.
			if (exists == false) {
				wordFreq[arrIndex].word = temp;
				wordFreq[arrIndex].count++;
				arrIndex++;
				temp.clear();
			}
		} else {
			temp += input[i];
		}
	}

	for (int i = 0; i < arrIndex; i++) {
		cout << wordFreq[i].word << " ; Its Frequency is: " << wordFreq[i].count << endl;
	}
	/* This is supposed to be getMostFreqWord. 
		The elements pertaining to each word's frequency is compared to each other
		via the array's indices. The most frequent word and its frequency is printed.*/
	int counter = 0;
	int maxIndex = 0;
	for (int i = 1; i < counter; i++) {
		if (wordFreq[maxIndex].count < wordFreq[i].count) {
			maxIndex = i;
		}
	}
	cout << "\nThe Most Frequent Word: " << wordFreq[maxIndex].word << "\nIts Freqeuncy: " << wordFreq[maxIndex].count << endl;
	return wordFreq;
}


