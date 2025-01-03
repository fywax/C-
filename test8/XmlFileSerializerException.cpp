#include <stdlib.h>
#include <iostream>
using namespace std;
#include <cstring>
#include "XmlFileSerializerException.h"

namespace planning
{
	int XmlFileSerializerException::NOT_ALLOWED = 1;
	int XmlFileSerializerException::FILE_NOT_FOUND = 2;
	int XmlFileSerializerException::END_OF_FILE = 3;

	XmlFileSerializerException::XmlFileSerializerException()
	{
		setCode(0);
		setMessage("");
	}

	XmlFileSerializerException::XmlFileSerializerException(int code, const string& message)
	{
		setCode(code);
		setMessage(message);
	}

	XmlFileSerializerException::XmlFileSerializerException(const XmlFileSerializerException& cop)
	{
	    setCode(cop.getCode());
	}

	void XmlFileSerializerException::setCode(int code)
	{
		this->code = code;
	}

	int XmlFileSerializerException::getCode() const
	{
		return this->code;
	}

	XmlFileSerializerException::~XmlFileSerializerException() {}

}