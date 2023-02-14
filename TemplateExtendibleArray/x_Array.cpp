// x_Array.cpp
#include "x_Array.h"
#include <iostream>
#include <cassert>



// Constructor
template <class T>
X_Array<T>::X_Array() {
	dataArray = new int *[1];
	dataArray[0] = new int[10];

	currLength = 0;
	tempLength = 0;
	currMax = 10;
	arrCounter = 0;
}

// Copy Constructor
template <class T>
X_Array<T>::X_Array( const X_Array<T> & rhs) {
	/*currMax = rhs.currMax;
	currLength = rhs.currLength;
	tempLength = rhs.tempLength;
	arrCounter = rhs.arrCounter;

	int ** temp = new int *[arrCounter];
	for ( int i = 0; i < currMax / 10; i++) {
		temp[i] = rhs.dataArray[i];
	}
	
	dataArray = temp;*/

	currMax = rhs.currMax;
	currLength = rhs.currLength;
	tempLength = rhs.tempLength;
	arrCounter = rhs.arrCounter;
	dataArray = new int *[currLength/10];
	for (int j = 0; j < currLength/10; j++) {
		dataArray[j] = new int[10];

		for (int k = 0; k < 10; k++) {
			dataArray[j][k] = rhs.dataArray[j][k];
		}
	}

}

// Destructor
template <class T>
X_Array<T>::~X_Array() {
	for (int i = 0; i < currMax/10; i++) {
		delete [] dataArray[i];
	}
	delete [] dataArray;
}



// Operator = 
template <class T>
X_Array<T> & X_Array<T>::operator = ( const X_Array<T> & rhs) {
	/*if ( this == & rhs) {
		return * this;
	}

	currMax = rhs.currMax;
	currLength = rhs.currLength;
	tempLength = rhs.tempLength;
	arrCounter = rhs.arrCounter;

	int ** temp = new int *[arrCounter];
	for ( int i = 0; i < currMax / 10; i++) {
		temp[i] = rhs.dataArray[i];
	}
	delete [] dataArray;
	dataArray = temp;

	return * this;*/
	if ( *this == rhs) {
		return * this;
	}
	for (int i = 0; i < currMax/10; i++) {
		delete [] dataArray[i];
	}
	delete [] dataArray;

	currMax = rhs.currMax;
	currLength = rhs.currLength;
	tempLength = rhs.tempLength;
	arrCounter = rhs.arrCounter;
	dataArray = new int *[currLength/10];
	for (int j = 0; j < currLength/10; j++) {
		dataArray[j] = new int[10];

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
	
	int ** temp = new int *[arrCounter + 1];

	for ( int i = 0; i < arrCounter; i++) {
		temp[i] = dataArray[i];
	}

	temp[arrCounter] = new int[10];


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
	// if dataArray needs to hold 4 pointers to other arrays: dataArray = new int *[4];
	/*if ( currLength == currMax) {
		grow();
		pushValue( value);
		return currLength - 1;
	}
	else {
		pushValue( value);
		return currLength - 1;
	}*/
	if ( currLength < currMax) {
		int newLoc = currLength;
		int masterIndex = newLoc/10;
		int locIndex = newLoc % 10;
		dataArray[masterIndex][locIndex] = value;
		currLength++;
	}
	else {
		int numMasterElements = currLength/10;
		int ** temp = new int * [numMasterElements + 1];
		for (int i = 0; i < numMasterElements; i++) {
			temp[i] = dataArray[i];
		}
		temp[numMasterElements] = new int[10];
		delete dataArray;
		dataArray = temp;
		currMax = currMax + 10;
		add( value);
	}
	return currLength - 1;
}

//////////////////////////////////////////
// Delete the last element in the array
//////////////////////////////////////////
template <class T>
void X_Array<T>::removeLast() {
	/*if ( currLength > 0) {
		currLength--;
		tempLength--;
		dataArray[arrCounter][tempLength] = 0;
	}*/
	if ( currLength > 0) {
		currLength--;
		tempLength--;
		dataArray[arrCounter][currLength] = 0;
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
int X_Array<T>::getAt( int index) const {
	int intCounter = 0;
	if ( index < currMax && index >= 0) {
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
// sort
// 
// 
//////////////////////////////////////////
template <class T>
void X_Array<T>::sort() {
	for (int i = currLength; i > 0; i--) {
		for (int j = 0; j < i - 1; j++) {
			if ( getAt(j) > getAt(j + 1)) {
				int temp = getAt(j);
				setAt(j, getAt(j + 1));
				setAt( j + 1, temp);
			}
		}
	}

}


//////////////////////////////////////////
// sort
// 
// 
//////////////////////////////////////////
template <class T>
int X_Array<T>::find ( const T value) const {
	/*int temp = -1;
	for (int k = 0; k < currLength; k++) {
		if ( getAt(k) == value) {
			temp = k;
		}
	}
	return temp;*/

	int low = 0;
	int high = currLength - 1;
	while ( low <= high) {
		int mid = low + (high - low) / 2;
		if ( value == getAt(mid)) {
			return mid;
		}
		else if ( value > getAt(mid)) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return -1;
}

int main () {
	X_Array<int> a;
	X_Array<char> b;
	X_Array<string> c;
	a.add(99);
	b.add('z');
	c.add("str");
	cout << a.getAt(0) << endl;
	cout << b.getAt(0) << endl;
	cout << c.getAt(0) << endl;
	return (0);
}
