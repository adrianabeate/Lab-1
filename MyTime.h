#pragma once
// need doucumentation for each member function - similar to your last
// project

#include <iostream>

class MyTime
{
public:

    // CONVERT THESE CONSTRUCTORS INTO A SINGLE CONSTRUCTOR THAT USES 
    // DEFAULT ARGUMENTS
    MyTime(int h=0, int m=0);


    void Reset(int h, int m);

    MyTime operator + (const MyTime& t1, const MyTime& t2);

    MyTime operator - (const MyTime& t1, const MyTime& t2);

    MyTime operator * (const MyTime& t1, int num);

    MyTime operator / (const MyTime& t1, int num);

    std::istream& operator >>(std::istream& fin, MyTime& t);

    std::ostream& operator <<(std::ostream& fout, const MyTime& t);

    bool operator == (const MyTime& t1, const MyTime& t2);

    bool operator < (const MyTime& t1, const MyTime& t2);

    bool operator <= (const MyTime& t1, const MyTime& t2);

    void input(std::istream& ins);

    void output(std::ostream& outs);

    int get_hours() const { return hours; }
    int get_minutes() const { return minutes; }

private:
    void simplify();
    int hours;      // hours can be > 24
    int minutes;   // 0 <= minutes <= 59
};


