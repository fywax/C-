#ifndef TIMING // Définit le début du préprocesseur
#define TIMING

#include <iostream>
#include <stdlib.h>
#include <cstring>
#include "Time.h"
#include "TimingException.h"

using namespace std;

namespace planning
{
	class Timing {
	private:
	    string day;    // Attribut pour le jour
	    Time start;    // Attribut pour l'heure de début
	    Time duration; // Attribut pour la durée

	public:
	    static const string MONDAY;
	    static const string TUESDAY;
	    static const string WEDNESDAY;
	    static const string THURSDAY;
	    static const string FRIDAY;
	    static const string SATURDAY;
	    static const string SUNDAY;
	    Timing(); // Constructeur par défaut
	    Timing(const string& day, const Time &start, const Time &duration); // Nouveau constructeur
	    Timing(const Timing &cop); // Constructeur de copie
	    ~Timing(); // Destructeur

	    void setDay(const string &day); // Setter pour le jour
	    string getDay() const; // Getter pour le jour

	    void setStart(const Time &start); // Setter pour l'heure de début
	    Time getStart() const; // Getter pour l'heure de début

	    void setDuration(const Time &duration); // Setter pour la durée
	    Time getDuration() const; // Getter pour la durée

	    void display() const; // Méthode pour afficher les informations de l'objet

	    bool operator==(const Timing& t);
        bool operator<(const Timing& t);
        bool operator>(const Timing& t);

        friend ostream& operator<<(ostream& sortie,const Timing& t);
        friend istream& operator>> (istream& entree, Timing& t); 

        static int J2C(const std::string& day);
	};
}
#endif // TIMING