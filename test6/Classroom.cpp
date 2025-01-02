#include <stdlib.h>
#include <iostream>
using namespace std;
#include <cstring>
#include "Classroom.h"

Classroom::Classroom()
{
	setId(0);
	setName("");
    setSeatingCapacity(0);
}

Classroom::Classroom(int id, const string& nom, int capa)
{
	setId(id);
	setName(nom);
    setSeatingCapacity(capa);
}

Classroom::Classroom(const Classroom& cop)
{
    setId(cop.getId());
    setName(cop.getName());
    setSeatingCapacity(cop.getSeatingCapacity());
}



Classroom& Classroom::operator=(const Classroom& egal)
{
    if (this != &egal) {  // Vérification de l'auto-affectation
        setId(egal.getId());
        setName(egal.getName());
        setSeatingCapacity(egal.getSeatingCapacity());
    }
    return *this;
}

ostream& operator<<(ostream& sortie, const Classroom& c) 
{ 
    sortie << "<Classroom>" << endl;
    sortie << "  <id>" << endl;
    sortie << "    " << c.getId() << endl;
    sortie << "  </id>" << endl;
    sortie << "  <name>" << endl;
    sortie << "    " << c.getName() << endl;
    sortie << "  </name>" << endl;
    sortie << "  <seatingCapacity>" << endl;
    sortie << "    " << c.getSeatingCapacity() << endl;
    sortie << "  </seatingCapacity>" << endl;
    sortie << "</Classroom>" << endl;
    return sortie; 
}

istream& operator>>(istream& entree, Classroom& c)
{
    string line;

    // Lire et vérifier les balises dans l'ordre

    getline(entree, line); // <Classroom>

    getline(entree, line); // <Id>

    getline(entree, line); // valeur id
    c.setId(stoi(line));

    getline(entree, line); // </Id>

    getline(entree, line); // <Name>

    getline(entree, line); //  valeur name
    c.setName(line);

    getline(entree, line); // </Name>

    getline(entree, line); // <SeatingCapacity>

    getline(entree, line); //  valeur SeatingCapacity
    c.setSeatingCapacity(stoi(line));

    getline(entree, line); // </SeatingCapacity>

    getline(entree, line); // </Classroom>

    return entree;
}


void Classroom::setName(const string& nom)
{
	this->name = nom;
}

void Classroom::setSeatingCapacity(int capa)
{
    this->seatingCapacity = capa;
}

string Classroom::getName() const
{
	return this->name;
}

int Classroom::getSeatingCapacity() const
{
    return this->seatingCapacity;
}

string Classroom::toString() const
{
    return name + " (" + to_string(seatingCapacity) + ")";
}

string Classroom::tuple() const
{
    return to_string(getId()) + " ;(" + to_string(seatingCapacity) + ")";
}



Classroom::~Classroom() {}