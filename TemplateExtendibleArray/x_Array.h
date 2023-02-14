// homework03
// x_Array.h
// create an extendable 2d array with templates
// add sort and find functions
#ifndef X_ARRAY_H
#define X_ARRAY_H
#include <iostream>


template< class T>
class X_Array {
	public:
		//constructors
		X_Array();
		X_Array( const X_Array &);
		~X_Array();

		// operators
		X_Array & operator = ( const X_Array<T> &);
		bool operator == ( const X_Array<T> &) const;
		bool operator != ( const X_Array<T> &) const;

		// functions
		void pushValue( T value);
		void grow();
		int add( T value);
		void removeLast();
		int getSize() const;
		T getAt( int index) const;
		void setAt( int index, T value);

		void sort();
		int find ( const T & value) const;
	
	private:
		T ** dataArray;

		int currMax;
		int currLength;
		int arrCounter;
		int tempLength;
};
	
#include "x_Array.ipp"

#endif
