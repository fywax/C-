#include <stdlib.h>
#include <iostream>
using namespace std;
#include <cstring>
#include "Time.h"

namespace planning
{
	Time::Time()
	{
		sethour(0);
		setmin(0);
	}

	Time::Time(int h, int m)
	{
		sethour(h);
		setmin(m);
	}

	Time::Time(int m)
	{
		int hour, minute;
		hour = m / 60;
		minute = m % 60;

		sethour(hour);
		setmin(minute);
	}

	Time::Time(const Time & cop)
	{
		sethour(cop.gethour());
		setmin(cop.getmin());
	}

	Time::~Time()
	{

	}

	void Time::sethour(int h)
	{
		if (h<0) return;
		this->hour = h;
	}

	void Time::setmin(int m)
	{
		if (m<0) return;
		this->min = m;
	}

	int Time::gethour()const
	{
		return hour;
	}

	int Time::getmin()const
	{
		return min;
	}

	void Time::display() const
	{
		if(hour<10)
		{
			cout <<"0"<< hour;		
		}
		else
		{
			cout << hour;
		}

		cout << "h";

		if(min<10)
			cout<< "0"<< min;
		else
			cout << min;
	}
}