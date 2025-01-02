#ifndef TIMING
#define TIMING

#include <iostream>
#include <string>
#include "Time.h"

using namespace std;

namespace planning
{
	class Timing {
	private:
	    string day;
	    Time start; 
	    Time Duree; 

	public:
	    static const string MONDAY;
	    static const string TUESDAY;
	    static const string WEDNESDAY;
	    static const string THURSDAY;
	    static const string FRIDAY;
	    static const string SATURDAY;
	    static const string SUNDAY;

	    Timing(); 
	    Timing(string day);
	    Timing(string day, Time start, Time Duree); 
	    Timing(const Timing &t);
	    ~Timing();

	    void setDay(const string day);
	    string getDay() const;

	    void setStart(const Time &start);
	    Time getStart() const;

	    void setDuree(const Time &Duree);
	    Time getDuree() const;

	    void display() const;
	};
}
#endif