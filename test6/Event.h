#ifndef EVENT // définis le début
#define EVENT

#include <stdlib.h>
#include <iostream>
#include "Timing.h"
#include "TimingException.h"

using namespace std;

namespace planning 
{

    class Event {
        private : 
            Timing * timing = nullptr;
            int code;
            string title;
        public : 
            static int currentCode;
            Event();
            Event(int c, const string& title);
            Event(const Event & e);
            ~Event();

            friend ostream& operator<<(ostream& sortie,const Event& e);
            friend istream& operator>>(istream& entree, Event& e); 


            void setTiming(const Timing& timing);
            Timing* getTiming() const;
            void setCode(int c);
            void setTitle(const string& title);
            int getCode() const;
            string getTitle() const;
            void display() const;
    };

}

#endif // définis la fin