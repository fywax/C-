#include <stdlib.h>
#include <iostream>
using namespace std;
#include <cstring>
#include "Event.h"

namespace planning
{
    int Event::currentCode = 0;

    Event::Event() // Classe :: fonction permet de dire ce qu'elle fait  , Quand c'est vide c'est constructeut par défaut
        {
        setCode(1);
        title = nullptr;
        setTitle("default");
        }

    Event::Event( int c, const char* t)  // Quand en parametre c'est des int char etc c'est un initialisation
        {
         setCode(c);
         title = nullptr;
         setTitle(t);
        }

    Event::Event(const Event & e){ // Quand en parametre c'est un objet de type de notre classe c'est le constructeur de copie
        setCode(e.getCode());
        title = nullptr;
        setTitle(e.getTitle());
        }
    void Event::setCode(int c)
        {
            if(c<=0) return;
            code = c;
        }

    void Event::setTitle(const char* t)
        {
            if(title) delete title;
            title = new char [strlen(t)+1];
            strcpy(title,t);
        }

    int Event::getCode() const
        {
            return code;
        }

    const char * Event:: getTitle() const
        {
            return title;
        }

    void Event::setTiming(const Timing& timing) 
    {    
        this->timing = new Timing(timing);
    }


    Timing* Event::getTiming() const 
    {
        return timing; 
    }


    void Event::display() const 
    {
        cout << "Event (" << code << ") : " << title << endl;
        if (timing != nullptr) {
            timing->display(); // Appelle display() sur l'objet Timing
        } else {
            cout << "Timing n'est pas défini." << endl;
        }
    }


    Event :: ~Event() // a chaque fois que c'est un pointeur faut le mettre dedans 
        {
            if(title)
                delete title;
        }

}