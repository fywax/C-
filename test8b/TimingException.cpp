#include <stdlib.h>
#include <iostream>
using namespace std;
#include <cstring>
#include "TimingException.h"

namespace planning
{

	int TimingException::INVALID_DAY = 4;
	int TimingException::NO_TIMING = 5;

	TimingException::TimingException()
	{
		setCode(0);
		setMessage("");
	}

	TimingException::TimingException(int code, const string& message)
	{
		setCode(code);
		setMessage(message);
	}

	TimingException::TimingException(const TimingException& cop)
	{
	    setCode(cop.getCode());
	}

	void TimingException::setCode(int code)
	{
		this->code = code;
	}

	int TimingException::getCode() const
	{
		return this->code;
	}

	TimingException::~TimingException() {}

}