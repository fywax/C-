#include <stdlib.h>
#include <iostream>
using namespace std;
#include <cstring>


#ifndef SCHEDULABLE // définis le début
#define SCHEDULABLE

class Schedulable {
private:
    int id;
public:

	Schedulable();
	Schedulable(int id);
    Schedulable(const Schedulable& cop);
    virtual ~Schedulable();  

    void setId(int id);
    int getId() const;

    virtual string toString() const = 0;
    virtual string tuple() const = 0;
};

#endif
