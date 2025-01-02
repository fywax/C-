#include <stdlib.h>
#include <iostream>
using namespace std;
#include <cstring>

#ifndef EVENT // définis le début
#define EVENT

class Event {
    private : 
        int code;
        char * title;
    public : 
    Event();
    Event(int c, const char* t);
    Event(const Event & e);
    ~Event();

    void setCode(int c);
    void setTitle(const char* t);
    int getCode() const;
    const char * getTitle() const;
    void display() const;
};

#endif // définis la fin