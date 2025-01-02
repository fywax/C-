#include <stdlib.h>
#include <iostream>
using namespace std;
#include <cstring>
#include "schedulable.h"

Schedulable::Schedulable()
{
	setId(0);
}

Schedulable::Schedulable(int ID)
{
	setId(ID);
}

Schedulable::Schedulable(const Schedulable& cop)
{
    setId(cop.getId());
}

void Schedulable::setId(int ID)
{
	if(ID<=0) 
		return;
	this->id = ID;
}

int Schedulable::getId() const
{
	return this->id;
}

Schedulable::~Schedulable() {}