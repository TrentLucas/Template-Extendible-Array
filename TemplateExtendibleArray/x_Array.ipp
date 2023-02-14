// x_Array.ipp
// in this file are constructors, destructors, operators, and functions
#include "x_Array.h"	// do not think these are needed, but is here just incase
#include <iostream>
#include <cassert>



// Constructor
template <class T>
X_Array<T>::X_Array() {
	dataArray = new T *[1];
	dataArray[0] = new T[10];

	currLength = 0;
	tempLength = 0;
	currMax = 10;
	arrCounter = 0;
}

// Copy Constructor
template <class T>
X_Array<T>::X_Array( const X_Array<T> & rhs) {
	currMax = rhs.currMax;
	currLength = rhs.currLength;
	tempLength = rhs.tempLength;
	arrCounter = rhs.arrCounter;

	dataArray = new T *[arrCounter + 1];
	for (int i = 0; i < arrCounter + 1; i++) {
		dataArray[i] = new T[10];

		for (int j = 0; j < 10; j++) {
			dataArray[i][j] = rhs.dataArray[i][j];
		}
	}
}

// Destructor
template <class T>
X_Array<T>::~X_Array() {
	for (int i = 0; i < arrCounter + 1; i++) {
		delete [] dataArray[i];
	}
	delete [] dataArray;
}



// Operator = 
template <class T>
X_Array<T> & X_Array<T>::operator = ( const X_Array<T> & rhs) {
	if ( *this == rhs) {
		return * this;
	}
	for (int i = 0; i < arrCounter + 1; i++) {
		delete [] dataArray[i];
	}
	delete [] dataArray;

	currMax = rhs.currMax;
	currLength = rhs.currLength;
	tempLength = rhs.tempLength;
	arrCounter = rhs.arrCounter;

	dataArray = new T *[arrCounter];
	for (int j = 0; j < arrCounter + 1; j++) {
		dataArray[j] = new T[10];

		for (int k = 0; k < 10; k++) {
			dataArray[j][k] = rhs.dataArray[j][k];
		}
	}
	return * this;
}

// Operator == 
template <class T>
bool X_Array<T>::operator == ( const X_Array<T> & rhs) const {
	if ( this->currMax != rhs.currMax) {
		return false;
	}
	if ( this->currLength != rhs.currLength) {
		return false;
	}

	// complete row checker
	for ( int j = 0; j < arrCounter; j++) {
		for ( int i = 0; i < 10; i++) {
			if ( this->dataArray[j][i] != rhs.dataArray[j][i]) {
				return false;
			}
		}
	}

	// incomplete row checker
	for ( int k = 0; k < tempLength; k++) {
		if ( this->dataArray[arrCounter][k] != rhs.dataArray[arrCounter][k]) {
			return false;
		}
	}
	return true;
}

// Operator !=
template <class T>
bool X_Array<T>::operator != ( const X_Array<T> & rhs) const {
	if ( X_Array::operator == (rhs)) {
		return false;
	}
	return true;
}



//////////////////////////////////////////
// Grow dataArray when dataArray
// reaches a multiple of 10
//////////////////////////////////////////
template <class T>
void X_Array<T>::grow() {
	arrCounter++;
	tempLength = 0;
	currMax = currMax + 10;
	
	T ** temp = new T *[arrCounter + 1];

	for ( int i = 0; i < arrCounter; i++) {
		temp[i] = dataArray[i];
	}

	temp[arrCounter] = new T[10];


	delete dataArray;


	dataArray = temp;
	
}

//////////////////////////////////////////
// Push a given value onto dataArray
// and increase count variables
//////////////////////////////////////////
template <class T>
void X_Array<T>::pushValue( T value) {
	dataArray[arrCounter][tempLength] = value;
	tempLength++;
	currLength++;
}

//////////////////////////////////////////
// Add an element to the end of the array
// return the index where we added the element
//  This call will automatically grow our memory
//  as needed
//////////////////////////////////////////
template <class T>
int X_Array<T>::add( T value) {
	if ( currLength == currMax) {
		grow();
		pushValue( value);
		return currLength - 1;
	}
	else {
		pushValue( value);
		return currLength - 1;
	}
}

//////////////////////////////////////////
// Delete the last element in the array
//////////////////////////////////////////
template <class T>
void X_Array<T>::removeLast() {
	if ( currLength > 0) {
		currLength--;
		tempLength--;
	}
}

//////////////////////////////////////////
// Get the current number of elements in the array
//////////////////////////////////////////
template <class T>
int X_Array<T>::getSize() const {
	return currLength;
}

//////////////////////////////////////////
// Get the element at the index
// return 0 if the index is out of bounds
//////////////////////////////////////////
template <class T>
T X_Array<T>::getAt( int index) const {
	int intCounter = 0;
	if ( index < currLength && index >= 0) {
		while ( index >= 10) {
			index = index - 10;
			intCounter++;
		}
		return dataArray[intCounter][index];
	}
	else {
		return 0;
	}
}

//////////////////////////////////////////
// setAt.  Puts the value at a specific location
// fails silently if index is out
// of bounds
//////////////////////////////////////////
template <class T>
void X_Array<T>::setAt( int index, T value) {
	int intCounter = 0;
	if ( index < currMax && index >= 0) {
		while ( index >= 10) {
			index = index - 10;
			intCounter++;
		}
		dataArray[intCounter][index] = value;
	}
}

//////////////////////////////////////////
// sort through the array using a 
// bubble sort
//////////////////////////////////////////
template <class T>
void X_Array<T>::sort() {
	for (int i = currLength; i > 0; i--) {
		for (int j = 0; j < i - 1; j++) {
			if ( getAt(j) > getAt(j + 1)) {
				T temp = getAt(j);
				setAt(j, getAt(j + 1));
				setAt( j + 1, temp);
			}
		}
	}
}

//////////////////////////////////////////
// find. takes in a value and searches 
// through the array using a binary search.
// If the element isn't found, return -1
// else return index
//////////////////////////////////////////
template <class T>
int X_Array<T>::find ( const T & value) const {
	int low = 0;
	int high = currLength - 1;

	while ( low <= high) {
		int mid = low + (high - low) / 2;
		if ( value == getAt(mid)) {
			return mid;
		}
		else if ( value < getAt(mid)) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return -1;
}
