#include <iostream>
#include <string>
#include "Timing.h"
using namespace std;

namespace planning
{

    const string Timing::MONDAY = "Lundi";
    const string Timing::TUESDAY = "Mardi";
    const string Timing::WEDNESDAY = "Mercredi";
    const string Timing::THURSDAY = "Jeudi";
    const string Timing::FRIDAY = "Vendredi";
    const string Timing::SATURDAY = "Samedi";
    const string Timing::SUNDAY = "Dimanche";

    Timing::Timing() {
        setDay("Lundi");
        setStart(Time());   
        setDuree(Time());
    }

    Timing::Timing(string day) {
        setDay(day);
    }

    Timing::Timing(std::string day, Time start, Time Duree) {
        setDay(day);
        setStart(start);
        setDuree(Duree);
    }

    Timing::Timing(const Timing& cop) {
        setDay(cop.getDay());
        setStart(cop.getStart());
        setDuree(cop.getDuree());
    }

    Timing::~Timing() 
    {
        
    }


    void Timing::setDay(const string day) {
        if(day == MONDAY || day == TUESDAY || day == WEDNESDAY || day == THURSDAY ||
            day == FRIDAY || day == SATURDAY || day == SUNDAY) 
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

    void Timing::setDuree(const Time &Duree) {
        Time tempDuree = Duree;
        
        int totalMinutes = Duree.gethour() * 60 + Duree.getmin();
        int hours = totalMinutes / 60;
        int minutes = totalMinutes % 60;

        tempDuree.sethour(hours);
        tempDuree.setmin(minutes);

        this->Duree = tempDuree;
    }


    string Timing::getDay() const {
        return day;
    }

    Time Timing::getStart() const {
        return start;
    }

    Time Timing::getDuree() const {
        return Duree;
    }

    void Timing::display() const {
        cout << "Rendez-vous : " << day << " à ";
        start.display();
        cout << "pour une durée de ";
        Duree.display();
        cout << endl;
    }
}