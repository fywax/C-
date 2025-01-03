#include <stdlib.h>
#include <iostream>
using namespace std;
#include <cstring>
#include "TimeException.h"

namespace planning
{

	int TimeException::INVALID_HOUR = 1;
	int TimeException::INVALID_MINUTE = 2;
	int TimeException::OVERFLOW = 3;

	TimeException::TimeException()
	{
		setCode(0);
		setMessage("");
	}

	TimeException::TimeException(int code, const string& message)
	{
		setCode(code);
		setMessage(message);
	}

	TimeException::TimeException(const TimeException& cop)
	{
	    setCode(cop.getCode());
	}

	void TimeException::setCode(int code)
	{
		this->code = code;
	}

	int TimeException::getCode() const
	{
		return this->code;
	}

	TimeException::~TimeException() {}

}