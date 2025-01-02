#ifndef EVENT
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
            const Timing* getTiming() const;

            void setCode(int c);
            int getCode() const;

            void setTitle(const char* t);
            const char * getTitle() const;

            void display() const;
    };

}
#endif
