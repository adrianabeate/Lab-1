// The implementation file for the MyTime class
#include "MyTime.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;
// Constructors
MyTime::MyTime() {
	hours = 0;
	minutes = 0;
}

MyTime::MyTime(int h, int m) {
	hours = h;
	minutes = m;
}

void MyTime::Reset(int h, int m) {
	hours = h;
	minutes = m;
}

void MyTime::simplify() {
	hours += minutes / 60;
	minutes = minutes % 60;
}

MyTime operator + (const MyTime& t1, const MyTime& t2) {
	MyTime tmp;
	tmp.hours = t1.hours + t2.hours;
	tmp.minutes = t1.minutes + t2.minutes;
	tmp.simplify();
	return tmp;
}

MyTime operator - (const MyTime& t1, const MyTime& t2) {
	MyTime tmp;
	tmp.minutes = abs((t1.hours * 60 + t1.minutes) -
		(t2.hours * 60 + t2.minutes));
	tmp.simplify();
	return tmp;
}

MyTime operator / (const MyTime& t1, int num) {
	MyTime tmp;
	tmp.minutes = t1.hours * 60 + t1.minutes;
	tmp.minutes /= num;
	tmp.simplify();
	return tmp;
}

MyTime operator * (const MyTime& t1, int num) {
	MyTime tmp;
	tmp.minutes = t1.hours * 60 + t1.minutes;
	tmp.minutes *= num;
	tmp.simplify();
	return tmp;
}

bool operator == (const MyTime& t1, const MyTime& t2) {
	return t1.hours == t2.hours && t1.minutes == t2.minutes;
}

bool operator < (const MyTime& t1, const MyTime& t2) {
	return (t1.hours * 60 + t1.minutes) < (t2.hours * 60 + t2.minutes);
}

bool operator <=(const MyTime& t1, const MyTime& t2) {
	return (t1.hours * 60 + t1.minutes) <= (t2.hours * 60 + t2.minutes);
}

void MyTime::input(istream& ins) {
	// Here you are to copy the implementation code from the >> operator shown below
 // remember to that variables will be local here - so no referene to t1
	//Then you can have the >> operator call this function.
   // In the .h file remove the word friend for the operator and move its prototype to a spot
   // under the class declaration
}

void MyTime::output(ostream& outs) {
	// Do the same thing a you did for the function above except using the code for the << 
	//operator
}


ostream& operator <<(ostream& outs, const MyTime& t1) {
	outs << t1.hours << ':' << setw(2) << setfill('0') << t1.minutes;
	return outs;
}

istream& operator >> (istream& ins, MyTime& t1) {
	char junk;
	ins >> t1.hours;
	ins.get(junk);
	ins >> t1.minutes;
	t1.simplify();
	return ins;
}
