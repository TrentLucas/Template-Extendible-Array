//  TEst driver for sorted array


#include <iostream>
#include "x_Array.h"
#include <cassert>



using namespace std;

void printArrayInt( const X_Array<int>  &);
void printArrayChar( const X_Array<char>  &);
void printArrayStr( const X_Array<string>  &);
void printArrayDoub( const X_Array<double>  &);


void testone();
void testtwo();
void testthree();
void testfour();
void testfive();
void testsix();
void testseven();
///////////////////////////////////////////////////////////
// Our test procedure
// Create array1 and add 101 elements
//

int main ()
{

    cout << "Performing test one"<<endl;
    testone();
    cout << "Performing test two"<<endl;
    testtwo();
    cout << "Performing test three"<<endl;
    testthree();
    cout << "Performing test four"<<endl;
    testfour();
    cout << "Performing test five"<<endl;
    testfive();
    cout << "Performing test six"<<endl;
    testsix();
    cout << "Performing test seven" << endl;
    testseven();



    cout << "Passed all tests"<<endl;
    return (0);
}

//////////////////////////////////////
// Test that an automatic and dynamic array 
//  extends appropriately and does not crash
/////////////////////////////////////////
void testone()
{

    X_Array<int> a1;
    X_Array<int> * pa = new X_Array<int>();

    for ( int i = 0 ; i < 161 ; i++) {
	a1.add(i);
	pa -> add ( i*2);
    }

    assert ( a1.getSize() == 161);
    cout << "Print a1"<<endl;
    printArrayInt(a1);
    cout << "Print *pa "<<endl;
    printArrayInt(*pa);


    delete pa;
}



///////////////////////////////////////////
//  TEst for operator =
/////////////////////////////////////////
void testtwo()
{
    X_Array<int> a1;
    for ( int i = 0 ; i < 50 ; i++) {
	a1.add(i);
    }

    X_Array<int> a2 = a1;

    X_Array<int> * pa= new X_Array<int>();
    (*pa) = a2;


    cout << "Print a1"<<endl;
    printArrayInt(a1);
    cout << "Print *pa "<<endl;
    printArrayInt(*pa);

    delete pa;

}


///////////////////////////////////
// test for operator == iteratigvely
///////////////////////////////////
void testthree()
{
    X_Array<int> a1;
    X_Array<int> * pa;
    pa = new X_Array<int>;

    for ( int i = 0 ; i < 101 ; i++) {
	a1.add(i);
	pa->add(i);
    }
    assert ( a1 == (*pa));

    a1.add(0);
    assert ( a1 != (*pa));
    delete pa;
}

//////////////////////////////////////////
//  TEsting for pathological operator =
///////////////////////////////////////
void testfour()
{
    X_Array<int> a1;
    X_Array<int> * pa = & a1;

    for ( int i = 0 ; i < 101 ; i++) {
	a1.add(i);
	pa->add(i);
    }

    a1 = *pa;

    assert ( a1 == a1);
    printArrayInt(a1);
}

////////////////////////////////////////////
//  Testing the setAt and getAt function
////////////////////////////////////////////
void testfive()
{
    X_Array<int> a1;
    for ( int i = 0 ; i < 20 ; i++) {
	a1.add(i);
    }

    assert ( a1.getAt(3) == 3);
    assert( a1.getAt(20) == 0);
    assert ( a1.getAt(19) == 19);
    a1.setAt(-1, 10);
    a1.setAt( 0, 10);
    assert ( a1.getAt(0) == 10);
    a1.setAt(20, -1);
    assert( a1.getSize() == 20);
    a1.add(100);
    assert ( a1.getSize ()== 21);
    assert ( a1.getAt(20) == 100);
}
   

//////////////////////////////////////////
//  Test the removeLast method
// ////////////////////////////////////////
void testsix()
{
    X_Array<int> a1;
    a1.add(101);
    a1.add( 102);
    assert ( a1.getSize() == 2);
    a1.removeLast();
    assert( a1.getAt( 1) == 0);
    a1.removeLast();
    a1.removeLast();
    a1.removeLast();
    assert( a1.getSize() == 0);
    a1.add(99);
    assert( a1.getSize() == 1);
    assert( a1.getAt(0) == 99);

}
     

void testseven() {
	X_Array<int> a1; 
	a1.add(1);
	a1.add(13);
	a1.add(18);
	a1.add(12);	
	a1.add(4);
	a1.add(86);
	a1.add(99);
	a1.add(42);
	a1.add(23);
	a1.add(45);
	a1.add(1);
	a1.add(87);
	a1.add(52);
	a1.add(39);	
	a1.add(20);
	a1.add(11);
	a1.add(35);
	a1.add(74);
	a1.add(61);
	a1.add(91);
	a1.add(-3);
	a1.sort();
	printArrayInt(a1);	

	cout << a1.find(-3) << endl;
	cout << a1.find(1) << endl;
	cout << a1.find(4) << endl;
	cout << a1.find(11) << endl;
	cout << a1.find(12) << endl;
	cout << a1.find(13) << endl;
	cout << a1.find(18) << endl;
	cout << a1.find(20) << endl;
	cout << a1.find(23) << endl;
	cout << a1.find(35) << endl;
	cout << a1.find(39) << endl;
	cout << a1.find(42) << endl;
	cout << a1.find(45) << endl;
	cout << a1.find(52) << endl;
	cout << a1.find(61) << endl;
	cout << a1.find(74) << endl;
	cout << a1.find(86) << endl;
	cout << a1.find(87) << endl;
	cout << a1.find(91) << endl;
	cout << a1.find(99) << endl;
	cout << a1.find(0) << endl;
	cout << a1.find(100) << endl;
	cout << a1.find(-312) << endl;

	X_Array<int> a;
	X_Array<char> b;
	X_Array<string> c;
	X_Array<double> d;
	a.add(99);
	a.add(2132);
	a.add(-231);
	b.add('z');
	b.add('d');
	b.add('a');
	b.add('w');
	b.add('n');
	b.add('m');
	b.add('u');
	b.add('o');
	b.add('p');
	b.add('y');
	b.add('t');
	b.add('r');


	c.add("str");
	c.add("dwr");
	c.add("str");
	c.add("f322f3");
	c.add("str");
	c.add("awfawr");
	c.add("sgjtr");
	c.add("sf3tr");
	c.add("swfafe4tr");
	c.add("stg4rer");
	c.add("swdadtr");
	c.add("swadwwtr");

	d.add(2.1);
	d.add(-14.0);
	d.add(3.1324);
	d.add(2.3);
	d.add(-0);
	d.add(3.1323);


	a.sort();
	b.sort();
	c.sort();
	d.sort();
	printArrayInt(a);
	printArrayChar(b);
	printArrayStr(c);
	printArrayDoub(d);

	cout << b.find('d') << endl;
	cout << b.find('q') << endl;
	cout << b.find('p') << endl;
	cout << c.find("str") << endl;
	cout << c.find("sgjtr") << endl;
	cout << c.find("dwagfewgts") << endl;
	cout << d.find(3.1224) << endl;
	cout << d.find(2.1) << endl;
	cout << "fdawdfwafwaefgwafwafawfwafawfewefesfefaqw" << endl;
	b.removeLast();
	c.removeLast();
	cout << b.getSize() << endl;
	cout << c.getSize() << endl;
	d.removeLast();
	cout << d.getSize() << endl;
	a1.setAt(0, 0);
	a1.setAt(1, 0);
	b.setAt(0, 'a');
	b.setAt(1, 'b');
	printArrayInt(a1);
	printArrayChar(b);

}

void printArrayInt( const X_Array<int>  & array)
{
    for ( int i = 0 ; i < array.getSize() ; i++) {
	cout << array.getAt(i) << "  ";
    }
    cout << endl;
}

void printArrayChar( const X_Array<char>  & array)
{
    for ( int i = 0 ; i < array.getSize() ; i++) {
	cout << array.getAt(i) << "  ";
    }
    cout << endl;
}

void printArrayStr( const X_Array<string>  & array)
{
    for ( int i = 0 ; i < array.getSize() ; i++) {
	cout << array.getAt(i) << "  ";
    }
    cout << endl;
}

void printArrayDoub( const X_Array<double>  & array)
{
    for ( int i = 0 ; i < array.getSize() ; i++) {
	cout << array.getAt(i) << "  ";
    }
    cout << endl;
}
