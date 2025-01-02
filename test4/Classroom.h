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

    friend ostream& operator<<(ostream& os, const Classroom& p);
    Classroom& operator=(const Classroom& other);

    void setName(const string& nom);
    void setSeatingCapacity(int capa);


    string getName() const;
    int getSeatingCapacity()const;

    string toString() const override;
    string tuple() const override;
};

#endif