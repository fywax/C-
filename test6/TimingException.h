#include <stdlib.h>
#include <iostream>
using namespace std;
#include <cstring>
#include "Exception.h"

#ifndef TIMINGEXCEPTION // définis le début
#define TIMINGEXCEPTION

namespace planning
{

    class TimingException : public Exception{
        private:
            int code;

        public:
        static int INVALID_DAY;
        static int NO_TIMING;
         
    	TimingException();
    	TimingException(int code, const string& message);
        TimingException(const TimingException& cop);
        ~TimingException();  

        void setCode(int code);
        int getCode() const;
    };

}

#endif