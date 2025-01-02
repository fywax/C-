#include <stdlib.h>
#include <iostream>
using namespace std;
#include <cstring>
#include "Group.h"

Group::Group()
{
	setId(0);
	setName("");
}

Group::Group(int id, const string& nom)
{
	setId(id);
	setName(nom);
}

Group::Group(const Group& cop)
{
    setId(cop.getId());
    setName(cop.getName());
}



Group& Group::operator=(const Group& egal)
{
    if (this != &egal) {  // Vérification de l'auto-affectation
        setId(egal.getId());
        setName(egal.getName());
    }
    return *this;
}

ostream& operator<<(ostream& os, const Group& p)
{
    os << p.toString();
    return os;
}



void Group::setName(const string& nom)
{
	this->name = nom;
}


string Group::getName() const
{
	return this->name;
}


string Group::toString() const
{
    return name;
}

string Group::tuple() const
{
    return to_string(getId()) + ";" + name;
}



Group::~Group() {}