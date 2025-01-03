#include <stdlib.h>
#include <iostream>
using namespace std;
#include <cstring>
#include "schedulable.h"

#ifndef GROUP // définis le début
#define GROUP

class Group : public Schedulable{
    private:
        string name;

    public:
	Group();
	Group(int id, const string& nom);
    Group(const Group& cop);
    ~Group();  

    friend ostream& operator<<(ostream& os, const Group& g);
    Group& operator=(const Group& g);
    bool operator<(const Group& g) const;


    void setName(const string& nom);
    string getName() const;

    string toString() const override;
    string tuple() const override;
};

#endif