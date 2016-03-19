/*	Name: Vivian Lee
    Compiler: Microsoft Visual Studio Express 2015 

File Description: The header contains header guards and necessary libraries.
The functions being called from the main method in HW1-1Main.cpp are 
declared here. */

#pragma once
#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <string>

using namespace std;

void getLeastFreqLetter(string input);
struct countWord;
countWord *countWordFreq(string info);

#endif