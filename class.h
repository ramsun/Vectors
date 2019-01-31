/*
Ramamurthy Sundar
class.h

Definition of ElectionVector, which is a vecor that will handle election results.

The ElectionVecor will keep track of a set of pointers, its own size and capacity.
.push_back() deals with how to properly scale size and caoacity.  There are also other
important member functions defined in the class.

*/
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

template<typename T>
class ElectionVector
{
private:
	T * ptr;
	size_t vsize;
	size_t capacity;

public:
	ElectionVector(size_t sz);
	~ElectionVector();
	size_t size() const;
	bool empty() const;
	void push_back(const T&);
	void pop_back();
	T& operator[](int);
	T& front();
	T& back();	 
};



