#include <stdlib.h>
#include <iostream>
using namespace std;
#include <cstring>
#include "XmlFileSerializer.h"

namespace planning
{
	int XmlFileSerializer::NOT_ALLOWED = 1;
	int XmlFileSerializer::FILE_NOT_FOUND = 2;
	int XmlFileSerializer::END_OF_FILE = 3;

	XmlFileSerializer::XmlFileSerializer()
	{
		setCode(0);
		setMessage("");
	}

	XmlFileSerializer::XmlFileSerializer(int code, const string& message)
	{
		setCode(code);
		setMessage(message);
	}

	XmlFileSerializer::XmlFileSerializer(const XmlFileSerializer& cop)
	{
	    setCode(cop.getCode());
	}

	void XmlFileSerializer::setCode(int code)
	{
		this->code = code;
	}

	int XmlFileSerializer::getCode() const
	{
		return this->code;
	}

	XmlFileSerializer::~XmlFileSerializer() {}

}