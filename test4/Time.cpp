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
        int hour = m / 60;
        int minute = m % 60;

        sethour(hour);
        setmin(minute);
    }

    Time::Time(const Time& cop)
    {
        sethour(cop.gethour());
        setmin(cop.getmin());
    }

    void Time::sethour(int h)
    {
        if (h < 0) return;
        this->hour = h;
    }

    void Time::setmin(int m)
    {
        if (m < 0) return;
        this->min = m;
    }

    int Time::gethour() const
    {
        return hour;
    }

    int Time::getmin() const
    {
        return min;
    }

    void Time::display() const
    {
        if (hour < 10)
        {
            cout << "0" << hour;		
        }
        else
        {
            cout << hour;
        }

        cout << "h";

        if (min < 10)
            cout << "0" << min;
        else
            cout << min;
    }

    Time::~Time() {}

    // Surcharge pour ajouter des minutes
    Time Time::operator+(int n) const
    {
        Time result(*this); // Copie de l'objet courant
        result.min += n; // Ajout de n minutes

        // Normalisation des minutes et des heures
        while (result.min >= 60) {
            result.hour++;
            result.min -= 60;
        }
        while (result.hour >= 24) {
            result.hour -= 24;
        }

        return result;
    }

    // Surcharge pour ajouter un entier à un objet Time
    Time operator+(int n, const Time& t)
    {
        return t + n; // Utilise la surcharge de Time + int
    }

    // Surcharge pour ajouter deux objets Time
    Time Time::operator+(const Time& t) const
    {
        Time result(*this); // Copie de l'objet courant
        result.hour += t.hour; 
        result.min += t.min; 

        // Normalisation
        while (result.min >= 60) {
            result.hour++;
            result.min -= 60;
        }
        while (result.hour >= 24) {
            result.hour -= 24;
        }

        return result;
    }

    // Surcharge pour soustraire des minutes
    Time Time::operator-(int n) const
    {
        Time result(*this); // Copie de l'objet courant
        result.min -= n; // Soustraction de n minutes

        // Normalisation des minutes et des heures
        while (result.min < 0) {
            result.hour--;
            result.min += 60;
        }
        while (result.hour < 0) {
            result.hour += 24;
        }

        return result;
    }

    // Surcharge pour soustraire un objet Time d'un autre
    Time Time::operator-(const Time& t) const
    {
        Time result(*this); // Copie de l'objet courant
        result.hour -= t.hour;
        result.min -= t.min;

        // Normalisation
        while (result.min < 0) {
            result.hour--;
            result.min += 60;
        }
        while (result.hour < 0) {
            result.hour += 24;
        }

        return result;
    }

    // Surcharge pour soustraire un nombre entier d'un objet Time
    Time operator-(int n, const Time& t)
    {
        int hour, min;
        hour = n / 60;
        min = n % 60;
        Time result(hour, min);
        return result - t;
    }

    // Surcharge de l'opérateur d'affectation
    Time& Time::operator=(const Time& t)
    {
        if (this != &t) {
            hour = t.hour;
            min = t.min;
        }
        return *this;
    }

    bool Time::operator==(const Time& t)
    {
    	if(this->hour == t.hour)
    	{
    		if(this->min == t.min)
    			return true;
    	}
   		return false;
    }

    bool Time::operator<(const Time& t)
    {
    	if(this->hour<t.hour)
    		return true;
    	else
    	{
    		if(this->hour == t.hour)
    		{
    			if(this->min < t.min)
    				return true;
    		}
    		
    	}
    	return false;
    }

    bool Time::operator>(const Time& t)
    {
    	if(this->hour>t.hour)
    		return true;
    	else
    	{
    		if(this->hour == t.hour)
    		{
    			if(this->min > t.min)
    				return true;
    		}
    	} 
   		return false;

    }

    ostream& operator<<(ostream& sortie,const Time& t) 
	{ 
	  sortie << t.hour << "h" << t.min; 
	  return sortie; 
	} 



	//ATTENTION PROBLEME SI ON SEPARE PAR UN ESPACE !
	istream& operator>>(istream& entree, Time& t) 
	{ 
	  int hour, min, erreur = 0;
	  char espace; 

	  entree >> hour >> espace >> min;

	  t.sethour(hour);
	  t.setmin(min);

	  return entree; 
	} 



	Time& Time::operator--() 
	{
	    min -= 30;
	    if (min < 0) 
	    {
	        min += 60; 
	        hour--;
	        if (hour < 0) {
	            hour += 24;
	        }
	    }
	    return *this; 
	}

	Time Time::operator++(int) 
	{
	    Time temp = *this;
	    ++(*this);
	    return temp;
	}

	Time& Time::operator++() 
	{
	    min += 30;
	    if (min >= 60) 
	    {
	        min -= 60;
	        hour++;
	        if (hour >= 24) 
	        {
	            hour -= 24; 
	        }
	    }
	    return *this; 
	}

	Time Time::operator--(int) 
	{
	    Time temp = *this; 
	    --(*this);
	    return temp; 
	}
}	
