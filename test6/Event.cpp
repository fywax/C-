#include "Event.h"
#include "Timing.h"
#include "Time.h"

using namespace std;

namespace planning
{
    int Event::currentCode = 0;

    Event::Event() // Classe :: fonction permet de dire ce qu'elle fait  , Quand c'est vide c'est constructeut par défaut
        {
        setCode(currentCode);
        setTitle("default");
        }

    Event::Event( int c, const string& t)  // Quand en parametre c'est des int char etc c'est un initialisation
        {
         setCode(c);
         currentCode = c;
         setTitle(t);
        }

    Event::Event(const Event & e){ // Quand en parametre c'est un objet de type de notre classe c'est le constructeur de copie
        setCode(e.getCode());
        setTitle(e.getTitle());
        }
    void Event::setCode(int c)
        {
            if(c<=0) return;
            code = c;
        }

    void Event::setTitle(const string& t)
        {
            title = t;
        }

    int Event::getCode() const
        {
            return code;
        }

    string Event:: getTitle() const
        {
            return title;
        }

    void Event::setTiming(const Timing& timing) 
    {    
        if(this->timing)
            delete this->timing; 
        this->timing = new Timing(timing);
    }


    Timing* Event::getTiming() const 
    {
        if(!timing)
        {
            throw TimingException(TimingException::NO_TIMING, "Pas d'objet de type Timing");
        }
        return timing; 
    }


    void Event::display() const 
    {
        cout << "Event (" << code << ") : " << title << endl;

        if(timing == nullptr)
            cout << "Pas de timing" << endl;
        else
        {
            if(timing->getDay() == "Lundi" && timing->getStart() == Time() && timing->getDuration() == Time())
                cout << "Pas de timing" << endl;
            else
                timing->display(); 

        }
    }


    Event :: ~Event() // a chaque fois que c'est un pointeur faut le mettre dedans 
        {
            if(timing)
                delete timing;
        }


    ostream& operator<<(ostream& sortie, const Event& e) 
    { 
        sortie << "<Event>" << endl;

        sortie << "<Code>" << endl;

        sortie << e.getCode() << endl;

        sortie << "</Code>" << endl;

        sortie << "<Title>" << endl;

        sortie << e.getTitle() << endl;

        sortie << "</Title>" << endl;


        if (e.timing) 
        {
            sortie << "<timing>" << endl;
            sortie << *(e.timing) << endl;
            sortie << "</timing>" << endl;
        }
        else 
        {            
            sortie << "<Erreur>" << endl;
            sortie << "Pas de timing" << endl;
            sortie << "</Erreur>" << endl;
        }


        sortie << "</Event>" << endl;

        return sortie; 
    }



    istream& operator>>(istream& entree, Event& e)
    {
        string line;
        Event temp;
        Timing timing;

        // Lire et vérifier les balises dans l'ordre
        getline(entree, line); // <Event>

        getline(entree, line); // <Code>

        getline(entree, line); // Valeur du code
        temp.setCode(stoi(line));  // Assigner le code à temp

        getline(entree, line); // </Code>

        getline(entree, line); // <Title>

        getline(entree, line); // valeur du titre
        temp.setTitle(line);    // Assigner title a temp

        getline(entree, line); // </Title>

        getline(entree, line);
        if(line == "<timing>")
        {
            entree >> timing;

            getline(entree, line);

            getline(entree, line);
        }

        e.setTiming(timing);
        e.setCode(temp.getCode());
        e.setTitle(temp.getTitle());

        return entree;
    }
}