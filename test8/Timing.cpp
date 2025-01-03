#include "Timing.h"
#include "Time.h"

using namespace std;

namespace planning
{

    const std::string Timing::MONDAY = "Lundi";
    const std::string Timing::TUESDAY = "Mardi";
    const std::string Timing::WEDNESDAY = "Mercredi";
    const std::string Timing::THURSDAY = "Jeudi";
    const std::string Timing::FRIDAY = "Vendredi";
    const std::string Timing::SATURDAY = "Samedi";
    const std::string Timing::SUNDAY = "Dimanche";

    Timing::Timing() {
        setDay("Lundi");
        setStart(Time());    // Initialise start avec un objet Time par défaut
        setDuration(Time()); // Initialise duration avec un objet Time par défaut
    }


    // Nouveau constructeur
    Timing::Timing(const string& day, const Time &start, const Time &duration) {
        setDay(day);          // Utilise la méthode pour définir le jour
        setStart(start);      // Utilise la méthode pour définir l'heure de début
        setDuration(duration); // Utilise la méthode pour définir la durée
    }

    Timing::Timing(const Timing& cop) {
        setDay(cop.getDay());
        setStart(cop.getStart());
        setDuration(cop.getDuration());
    }

    void Timing::setDay(const string& day) 
    {
        if(day == MONDAY || day == TUESDAY || day == WEDNESDAY || day == THURSDAY ||
            day == FRIDAY || day == SATURDAY || day == SUNDAY) 
        {
            this->day = day;
        	return;
        } 
        else 
        {
        	throw TimingException(TimingException::INVALID_DAY, day + " invalide");
        }
    }

    void Timing::setStart(const Time& s) 
    {
        start.setMinute(s.getMinute());
        start.setHour(s.getHour());
    }

    void Timing::setDuration(const Time& d)
    {
        duration.setMinute(d.getMinute());
        duration.setHour(d.getHour());
    }


    string Timing::getDay() const {
        return day;
    }

    Time Timing::getStart() const {
        return start;
    }

    Time Timing::getDuration() const {
        return duration;
    }

    void Timing::display() const {
        cout << "Rendez-vous : " << day << " à ";
        start.display(); // Affiche l'heure de début
        cout << " pour une durée de ";
        duration.display(); // Affiche la durée
        cout << endl;
    }

    Timing::~Timing() {}

    bool Timing::operator==(const Timing& t)
    {
        if(this->day == t.day)
        {
            if(this->start == t.start)
            {
                if(this->duration == t.duration)
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool Timing::operator<(const Timing& t)  
    {


        if (J2C(this->day) < J2C(t.day)) 
        {
            return true;  
        }
        else 
        {
            if (J2C(this->day) == J2C(t.day)) 
            {
                if (this->start < t.start) 
                {
                    return true;  
                }
                else
                {
                    if (this->start == t.start) 
                    {
                        return this->duration < t.duration;
                    } 
                }
            }
        }
        return false; 
    }

    bool Timing::operator>(const Timing& t)  
    {


        if (J2C(this->day) > J2C(t.day)) 
        {
            return true;  
        }
        else 
        {
            if (J2C(this->day) == J2C(t.day)) 
            {
                if (this->start > t.start) 
                {
                    return true;  
                }
                else
                {
                    if (this->start == t.start) 
                    {
                        return this->duration > t.duration;
                    } 
                }
            }
        }
        return false; 
    }

    ostream& operator<<(ostream& sortie, const Timing& t) 
    { 
        sortie << "<Timing>" << endl;

        sortie << "<Day>" << endl;
        sortie << t.getDay() << endl;
        sortie << "</Day>" << endl;

        sortie << "<Start>" << endl;
        sortie << t.getStart() << endl; //appel flux de sortie de type time car getStart() retourne Time
        sortie << "</Start>" <<endl;

        sortie << "<Duration>" << endl;
        sortie << t.getDuration() << endl; //appel flux de sortie de type time
        sortie << "</Duration>" << endl;


        sortie << "</Timing>";

        return sortie; 
    }



    istream& operator>>(istream& entree, Timing& t)
    {
        string line;
        Timing temp3;   // Utilisation de Timing temporaire pour stocker start et duration
        Time temp1, temp2;

        // Lire et vérifier les balises dans l'ordre
        getline(entree, line); // <Timing>

        getline(entree, line); // <Day>

        getline(entree, line); // Valeur du jour
        temp3.setDay(line);  // Assigner le jour à temp3

        getline(entree, line); // </Day>

        getline(entree, line); // <Start>
        entree >> temp1;    // Lire l'heure de début avec l'opérateur >> de Time

        getline(entree, line); // </Start>

        getline(entree, line); // <Duration>
        entree >> temp2;  // Lire la durée avec l'opérateur >> de Time

        getline(entree, line); // </Duration>

        getline(entree, line); // </Timing>

        // Finalement, on affecte à l'objet Timing principal `t`
        t.setDay(temp3.getDay());
        t.setStart(temp1);
        t.setDuration(temp2);

        return entree;
    }


    string Timing::toString() const 
    {
        return "Day: " + day + "\nStart: " + start.toString() + "\nDuration: " + duration.toString();
    }



    int Timing::J2C(const std::string& day) // jour à chiffre
    {
        if (day == MONDAY) return 0;
        if (day == TUESDAY) return 1;
        if (day == WEDNESDAY) return 2;
        if (day == THURSDAY) return 3;
        if (day == FRIDAY) return 4;
        if (day == SATURDAY) return 5;
        if (day == SUNDAY) return 6;
        return -1; // Jour invalide
    }
}