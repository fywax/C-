#include <stdlib.h>
#include <iostream>
#include <cstring>
using namespace std;


#ifndef SCHEDULABLE // définis le début
#define SCHEDULABLE

class Schedulable {
    private:
        int id;
    public:
        static int currentId;

    	Schedulable();
    	Schedulable(int id);
        Schedulable(const Schedulable& cop);
        virtual ~Schedulable();//car permettre aux filles d'y accéder 

        void setId(int id);
        int getId() const;

        virtual string toString() const = 0;
        virtual string tuple() const = 0;
};

#endif
