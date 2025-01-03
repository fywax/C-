#include <stdlib.h>
#include <iostream>
using namespace std;
#include <cstring>
#include "schedulable.h"

#ifndef CLASSROOM // définis le début
#define CLASSROOM

class Classroom : public Schedulable{
    private:
        string name;
        int seatingCapacity;

    public:
	Classroom();
	Classroom(int id, const string& nom, int capa);
    Classroom(const Classroom& cop);
    ~Classroom();  

    friend ostream& operator<<(ostream& sortie, const Classroom& c);
    friend istream& operator>>(istream& entree, Classroom& c);

    Classroom& operator=(const Classroom& c);
    bool operator<(const Classroom& c) const;

    void setName(const string& nom);
    void setSeatingCapacity(int capa);


    string getName() const;
    int getSeatingCapacity()const;

    string toString() const override;
    string tuple() const override;
};

#endif