/*	Name: Vivian Lee
	Compiler: Microsoft Visual Studio Express 2015

	Description: This header file contains header guards, necessary 
	libraries, and declarations for each function being called from
	the main method in HW1-2Main.cpp.*/

#pragma once
#ifndef HEADER_H
#define HEADER_h
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

void readData(vector<int>& intVector);
void printVector(const vector<int>& intVector);
void selectionSort(vector<int>& intVector);

#endif