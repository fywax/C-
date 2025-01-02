#include <stdlib.h>
#include <iostream>
using namespace std;
#include <cstring>
#include "Event.h"

namespace planning
{
    int Event::currentCode = 0;

    Event::Event()
        {
            timing = nullptr;
            setCode(1);
            title = nullptr;
            setTitle("default");
        }

    Event::Event( int c, const char* t) 
        {
         setCode(c);
         title = nullptr;
         setTitle(t);
        }

    Event::Event(const Event & e)
    { 
        setCode(e.getCode());
        title = nullptr;
        setTitle(e.getTitle());
    }

    Event::~Event()
    {
        if (title) 
            delete[] title;

        if (timing) 
            delete timing;
    }

    void Event::setCode(int c)
        {
            if(c<=0) return;
            code = c;
        }

    void Event::setTitle(const char* t)
    {
        if (title) delete[] title; 
        if (t) 
        {
            title = new char[strlen(t) + 1];
            strcpy(title, t);
        } 

        else 
        {
            title = nullptr;
        }
    }

    int Event::getCode() const
        {
            return code;
        }

    const char * Event:: getTitle() const
        {
            return title;
        }

    void Event::setTiming(const Timing& timing) 
    {    
        this->timing = new Timing(timing);
    }


    const Timing* Event::getTiming() const 
    {
        return timing; 
    }


    void Event::display() const 
    {
        cout << "Event (" << code << ") : " << title << endl;
        if (timing != nullptr) {
            timing->display();
        } else {
            cout << "Timing n'est pas défini." << endl;
        }
    }
}