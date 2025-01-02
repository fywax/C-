#include <stdlib.h>
#include <iostream>
using namespace std;
#include <cstring>

#ifndef EXCEPTION // définis le début
#define EXCEPTION

class Exception{
    private:
        string message;

    public:
	Exception();
	Exception(const string& message);
    Exception(const Exception& cop);
    ~Exception();  

    void setMessage(const string& nom);

    string getMessage() const;
};

#endif