#include <stdlib.h>
#include <iostream>
using namespace std;
#include <cstring>
#include "schedulable.h"

#ifndef PROFESSOR // définis le début
#define PROFESSOR

class Professor : public Schedulable{ //classe héritée
    private:
        string lastName;
        string firstName;

    public:
	Professor();
	Professor(int id, const string& nom, const string& prenom);
    Professor(const Professor& cop);
    ~Professor();  

    friend ostream& operator<<(ostream& os, const Professor& p);
    Professor& operator=(const Professor& p);
    bool operator<(const Professor& p) const;


    void setLastName(const string& nom);
    void setFirstName(const string& prenom);

    string getLastName() const;
    string getFirstName() const;

    string toString() const override;
    string tuple() const override;
};

#endif