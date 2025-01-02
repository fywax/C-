#include <stdlib.h>
#include <iostream>
using namespace std;
#include <cstring>
#include "Exception.h"

Exception::Exception()
{
	setMessage("");
}

Exception::Exception(const string& message)
{
	setMessage(message);
}

Exception::Exception(const Exception& cop)
{
    setMessage(cop.getMessage());
}

void Exception::setMessage(const string& message)
{
	this->message = message;
}

string Exception::getMessage() const
{
	return this->message;
}

Exception::~Exception() {}