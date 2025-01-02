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



Group& Group::operator=(const Group& g)
{
    if (this != &g) {  // Vérification de l'auto-affectation
        setId(g.getId());
        setName(g.getName());
    }
    return *this;
}

ostream& operator<<(ostream& sortie, const Group& g)
{
    sortie << g.toString();
    return sortie;
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