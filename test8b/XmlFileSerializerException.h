#include <stdlib.h>
#include <iostream>
using namespace std;
#include <cstring>
#include "Exception.h"

#ifndef XMLFILESERIALIZER // définis le début
#define XMLFILESERIALIZER

namespace planning
{ 

    class XmlFileSerializerException : public Exception{
        private:
            int code;

        public:
        static int NOT_ALLOWED;
        static int FILE_NOT_FOUND;
        static int END_OF_FILE;
         
    	XmlFileSerializerException();
    	XmlFileSerializerException(int code, const string& message);
        XmlFileSerializerException(const XmlFileSerializerException& cop);
        ~XmlFileSerializerException();  

        void setCode(int code);
        int getCode() const;
    };

}

#endif