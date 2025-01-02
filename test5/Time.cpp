#include <stdlib.h>
#include <iostream>
using namespace std;
#include <cstring>
#include "Time.h"

namespace planning
{
    Time::Time()
    {
        setHour(0);
        setMinute(0);
    }

    Time::Time(int h, int m)
    {
        setHour(h);
        setMinute(m);
    }

    Time::Time(int m)
    {
        if(m < 0 || m >= 1440)
        {
            throw TimeException(TimeException::OVERFLOW, "Durée entrée incorrect");
        }

        int hour = m / 60;
        int minute = m % 60;

        setHour(hour);
        setMinute(minute);
    }

    Time::Time(const Time& cop)
    {
        setHour(cop.getHour());
        setMinute(cop.getMinute());
    }

    void Time::setHour(int h)
    {
        if (h < 0 || h >= 24) 
        {
            throw TimeException(TimeException::INVALID_HOUR, to_string(h) + " invalide");
            return;
        }
        this->hour = h;
    }

    void Time::setMinute(int m)
    {
        if (m < 0 || m >= 60)
        {
            throw TimeException(TimeException::INVALID_MINUTE, to_string(m) + " invalide");
            return;
        }
        this->min = m;
    }

    int Time::getHour() const
    {
        return hour;
    }

    int Time::getMinute() const
    {
        return min;
    }

    void Time::display() const
    {
        if (this->hour < 10)
        {
            cout << "0" << hour;		
        }
        else
        {
            cout << hour;
        }

        cout << "h";

        if (this->min < 10)
            cout << "0" << min;
        else
            cout << min;
    }

    Time::~Time() {}

    // Surcharge pour ajouter des minutes
     Time Time::operator+(int n) const
    {
        Time result(*this); // Copie de l'objet courant
        int hour, min;
        hour = n / 60;
        min = n % 60;


        if(result.min + min >= 60)
        {
            hour += 1;
            min -= 60;
        }

        if(result.hour + hour >= 24)
        {
            throw TimeException(TimeException::OVERFLOW, "Dépassement de 23h59");
        }
        else
        {
            result.hour += hour;
            result.min += min;
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
        
        if(result.min + t.min >= 60)
        {
            result.hour += 1;
            result.min -= 60;
        }

        if(result.hour + t.hour >= 24)
        {
            throw TimeException(TimeException::OVERFLOW, "Dépassement de 23h59");
        }
        else
        {
            result.hour += t.hour;
            result.min += t.min;
        }

        return result;
    }

    // Surcharge pour soustraire des minutes
    Time Time::operator-(int n) const
    {
        Time result(*this); // Copie de l'objet courant

        // Soustraire les minutes
        int totalMinutes = result.hour * 60 + result.min - n;

        // Vérifier si nous tombons sous 00h00
        if (totalMinutes < 0) {
            throw TimeException(TimeException::OVERFLOW, "Dépassement de 00h00");
        }

        // Normaliser le temps dans la plage 0-1439 minutes
        result.hour = totalMinutes / 60;
        result.min = totalMinutes % 60;

        return result;
    }


    // Surcharge pour soustraire un objet Time d'un autre
    Time Time::operator-(const Time& t) const
    {
        Time result(*this); // Copie de l'objet courant
        
        if(result.min - t.min < 0)
        {
            result.hour -= 1;
            result.min += 60;
        }
        result.hour -= t.hour;
        result.min -= t.min;

        if((result.min < 0 && result.hour == 0) || result.hour < 0)
        {
            throw TimeException(TimeException::OVERFLOW, "Dépassement de 00h00");
        }

        return result;
    }

    // Surcharge pour soustraire un objet time d'une durée
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



    istream& operator>>(istream& entree, Time& t)
    {
        string tmp;
        Time timeTemp;

        entree >> tmp;

        if (tmp.size() != 5) 
        {
            cout << "Invalid Length !" << endl;
            exit(0);
        }

        timeTemp.setHour(stoi(tmp.substr(0,2)));
        timeTemp.setMinute(stoi(tmp.substr(3,2)));

        if (timeTemp.getHour() < 0 || timeTemp.getHour() > 24 || timeTemp.getMinute() < 0 || timeTemp.getMinute() > 60)
        {
            cout << "Invalid Time !" << endl;
            exit(0);
        }

        t.setHour(timeTemp.getHour());
        t.setMinute(timeTemp.getMinute());

        return entree;
    }



    Time Time::operator++() // Pré-incrémentation
    {
        *this = *this + 30; // Ajouter 30 minutes
        return *this;       // Retourner une référence à l'objet modifié
    }

    Time Time::operator++(int) // Post-incrémentation
    {
        Time time(*this);      // Créer une copie de l'objet courant
        *this = *this + 30;    // Ajouter 30 minutes
        return time;           // Retourner l'objet avant la modification
    }

    Time Time::operator--() // Pré-décrémentation
    {
        *this = *this - 30; // Soustraire 30 minutes
        return *this;       // Retourner une référence à l'objet modifié
    }

    Time Time::operator--(int) // Post-décrémentation
    {
        Time time(*this);      // Créer une copie de l'objet courant
        *this = *this - 30;    // Soustraire 30 minutes
        return time;           // Retourner l'objet avant la modification
    }


}
