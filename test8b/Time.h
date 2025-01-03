#include <stdlib.h>
#include <iostream>
using namespace std;
#include <cstring>
#include "TimeException.h"

#ifndef TIME // définis le début
#define TIME

namespace planning
{

    class Time {
    private:
        int hour;
        int min;
    public:
        Time();
        Time(int h, int m);
        Time(int m2);
        Time(const Time& cop);
        ~Time();

        void setHour(int h);
        int getHour() const;

        void setMinute(int m);
        int getMinute() const;

        void display() const;

        Time operator+(int n) const; 
        friend Time operator+(int n, const Time& t); 
        Time operator+(const Time& t) const; 

        Time operator-(int n) const; 
        Time operator-(const Time& t) const; 
        friend Time operator-(int n, const Time& t); 

        Time& operator=(const Time& t);

        bool operator==(const Time& t);
        bool operator<(const Time& t);
        bool operator>(const Time& t);

        friend ostream& operator<<(ostream& sortie,const Time& t);
        friend istream& operator>> (istream& entree, Time& t); 

        string toString() const;

	    Time operator++(); 
	    Time operator++(int); 
	    Time operator--();
	    Time operator--(int);
    };

}

#endif