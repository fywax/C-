#include <iostream>
#include <string>
#include "Timing.h"

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

    Timing::Timing(string day) {
        setDay(day);
    }

    Timing::Timing(Time t, bool commence) {
        if (commence)
            setStart(t);
        else
            setDuration(t);
    }

    // Nouveau constructeur
    Timing::Timing(std::string day, Time start, Time duration) {
        setDay(day);          // Utilise la méthode pour définir le jour
        setStart(start);      // Utilise la méthode pour définir l'heure de début
        setDuration(duration); // Utilise la méthode pour définir la durée
    }

    Timing::Timing(const Timing& cop) {
        setDay(cop.getDay());
        setStart(cop.getStart());
        setDuration(cop.getDuration());
    }

    void Timing::setDay(const string day) {
        if(day == "Lundi" || day == "Mardi" || day == "Mercredi" || day == "Jeudi" ||
            day == "Vendredi" || day == "Samedi" || day == "Dimanche") 
        {
            this->day = day;
        	return;
        } 
        else 
        {
        	cout << "Erreur : Le jour '" << day << "' n'est pas valide." << endl;
        }
        return;
    }

    void Timing::setStart(const Time& start) {
        this->start = start;
    }

    void Timing::setDuration(const Time &duration) {
        // Crée une copie modifiable de `duration`
        Time tempDuration = duration;
        
        int totalMinutes = duration.gethour() * 60 + duration.getmin();
        int hours = totalMinutes / 60;
        int minutes = totalMinutes % 60;

        tempDuration.sethour(hours);
        tempDuration.setmin(minutes);

        this->duration = tempDuration;  // Affecte la copie modifiée à l'attribut
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
        cout << "pour une durée de ";
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

    int Timing::J2C(const std::string& day) //jour à chiffre
    {
        if (day == "Monday") return 0;
        if (day == "Tuesday") return 1;
        if (day == "Wednesday") return 2;
        if (day == "Thursday") return 3;
        if (day == "Friday") return 4;
        if (day == "Saturday") return 5;
        if (day == "Sunday") return 6;
        return -1;
    }
}