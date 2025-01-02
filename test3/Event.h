#ifndef EVENT // définis le début
#define EVENT
#include <stdlib.h>
#include <iostream>
using namespace std;
#include <cstring>
#include "Timing.h"

namespace planning 
{


    class Event {
        private : 
            Timing * timing;
            int code;
            char * title;
        public : 
            static int currentCode;
            Event();
            Event(int c, const char* t);
            Event(const Event & e);
            ~Event();


            void setTiming(const Timing& timing);
            Timing* getTiming() const;
            void setCode(int c);
            void setTitle(const char* t);
            int getCode() const;
            const char * getTitle() const;
            void display() const;
    };

}

#endif // définis la fin
