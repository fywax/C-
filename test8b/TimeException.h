#include <stdlib.h>
#include <iostream>
using namespace std;
#include <cstring>
#include "Exception.h"

#ifndef TIMEEXCEPTION // définis le début
#define TIMEEXCEPTION

namespace planning
{ 

    class TimeException : public Exception{
        private:
            int code;

        public:
        static int INVALID_HOUR;
        static int INVALID_MINUTE;
        static int OVERFLOW;
         
    	TimeException();
    	TimeException(int code, const string& message);
        TimeException(const TimeException& cop);
        ~TimeException();  

        void setCode(int code);
        int getCode() const;
    };

}

#endif