#include <stdlib.h>
#include <iostream>
using namespace std;
#include <cstring>

namespace planning
{
    #ifndef TIME // définis le début
    #define TIME

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

        void sethour(int h);
        int gethour() const;

        void setmin(int m);
        int getmin() const;

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

	    Time& operator++(); 
	    Time operator++(int); 
	    Time& operator--();
	    Time operator--(int);
    };

    #endif
}
