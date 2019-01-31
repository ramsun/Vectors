/*
Ramamurthy Sundar
class.cpp

Implementation of class.h. All functions are commented bellow.

*/

#include "class.h"

using namespace std;

//constructor
template<typename T>
ElectionVector<T>::ElectionVector(size_t sz) : vsize(0), capacity(0), ptr(nullptr)
{
	if (sz == 0) return;
	ptr = new T[sz];
	vsize = sz;
	capacity = sz;
	for (size_t i = 0; i < vsize; i++) ptr[i] = T();
}

//destructor
template<typename T>
ElectionVector<T>::~ElectionVector() {
	if (ptr != nullptr) delete[] ptr;
}

//overloading the [] operator
template<typename T>
T& ElectionVector<T>::operator[](int index) {
	if (index < 0 || index > vsize) 
		throw exception("Out of Range");
	return ptr[index];
}

//return size of vector
template<typename T>
size_t ElectionVector<T>::size() const {
	return vsize;
}

//tells whether the vector is empty or not
template<typename T>
bool ElectionVector<T>::empty() const {
	return vsize == 0;
}

//create a new pointer in memory and change size and capacity 
template<typename T>
void ElectionVector<T>::push_back(const T & object)
{
	//must update the capacity if size and capacity are the same
	if (vsize == capacity) {
		if (capacity == 0) {
			capacity = 1;
			ptr = new T[1];
		}
		else
		{
			T * tempPtr;
			capacity *= 2;
			tempPtr = new T[capacity];
			for (size_t i = 0; i < vsize; i++) {
				tempPtr[i] = ptr[i];
			}
			if (ptr != nullptr) {
				delete[] ptr;
				ptr = NULL;
			}
			ptr = tempPtr;
		}
	}
	ptr[vsize] = object;
	vsize++;
}

//remove last pointer
template<typename T>
void ElectionVector<T>::pop_back(){
	if (vsize == 0) 
		throw exception("Nothing to delete");
	vsize--;
}


//return front of the the vector
template<typename T>
T& ElectionVector<T>::front() {
	if (vsize == 0)
		throw exception("Vector is empty");
	return ptr[0];
}


//return the back of the vector
template<typename T>
T& ElectionVector<T>::back() {
	if (vsize == 0)
		throw exception("Vector is empty");
	return ptr[vsize-1];
}

//potential types that will be used in main
template class ElectionVector<int>;
template class ElectionVector<std::string>;
template class ElectionVector<double>;
template class ElectionVector<unsigned int>;
