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

    MyTime MyTime::operator + ( const MyTime& t2)const
    {   MyTime tmp;

	tmp.hours = hours + t2.hours;
	tmp.minutes = minutes + t2.minutes;

	tmp.simplify();

	return tmp;
    }

    MyTime operator - (const MyTime& t1, const MyTime& t2)
    {MyTime tmp;

	tmp.minutes = abs((t1.hours * 60 + t1.minutes) -

		(t2.hours * 60 + t2.minutes));

	tmp.simplify();

	return tmp;
    }

    MyTime operator * (const MyTime& t1, int num)
    {MyTime tmp;

	tmp.minutes = t1.hours * 60 + t1.minutes;

	tmp.minutes *= num;

	tmp.simplify();

	return tmp;
    }

    MyTime operator / (const MyTime& t1, int num)
    {	MyTime tmp;

	tmp.minutes = t1.hours * 60 + t1.minutes;

	tmp.minutes /= num;

	tmp.simplify();

	return tmp;
    }

    std::istream& operator >>(std::istream& fin, MyTime& t);

    std::ostream& operator <<(std::ostream& fout, const MyTime& t);

    bool operator == (const MyTime& t1, const MyTime& t2)
    { return t1.hours == t2.hours && t1.minutes == t2.minutes;
    }

    bool operator < (const MyTime& t1, const MyTime& t2)
    {return (t1.hours * 60 + t1.minutes) < (t2.hours * 60 + t2.minutes);
    }

    bool operator <= (const MyTime& t1, const MyTime& t2)
    {return (t1.hours * 60 + t1.minutes) <= (t2.hours * 60 + t2.minutes);
    }

    void input(std::istream& ins);

    void output(std::ostream& outs);

    int get_hours() const { return hours; }
    int get_minutes() const { return minutes; }

private:
    void simplify();
    int hours;      // hours can be > 24
    int minutes;   // 0 <= minutes <= 59
};

 std::istream& operator >>(std::istream& fin, MyTime& t);

    std::ostream& operator <<(std::ostream& fout, const MyTime& t);
