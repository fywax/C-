#include "Timetable.h"
#include "schedulable.h"

using namespace std;

// Constructor
Timetable::Timetable() 
{

}

// Destructor
Timetable::~Timetable() {}

// ajout
int Timetable::addClassroom(const string& name,int seatingCapacity)
{
    Schedulable::currentId += 1;
    Classroom c(Schedulable::currentId, name, seatingCapacity);

    auto result = classrooms.insert(c); // Insère l'élément dans le set
    if (result.second == false) // Vérifie si l'insertion a échoué
    { 
        cout << "La salle existe déjà" << endl;
        return -1;
    }

    cout << "Classe " << name << " bien ajoutée" << endl;
    return Schedulable::currentId;
}

int Timetable::addProfessor(const string& lastName, const string& firstName) 
{
    Schedulable::currentId += 1;
    Professor p(Schedulable::currentId, lastName, firstName);

    auto result = professors.insert(p);
    if(result.second == false)
    {
        cout << "Le prof existe déja" << endl;
        return -1;
    }

    cout << "Prof " << firstName << " " << lastName << " bien ajouté" << endl;
    return Schedulable::currentId;
}

int Timetable::addGroup(const string& name) 
{
    Schedulable::currentId += 1;
    Group g(Schedulable::currentId, name);
    auto result = groups.insert(g);
    if(result.second == false)
    {
        cout << "Le groupe existe déja" << endl;
        return -1;
    }

    cout << "Groupe " << name << " bien ajouté" << endl;
    return Schedulable::currentId;
}


// Find 
Classroom Timetable::findClassroomByIndex(int index) const 
{
    auto it = classrooms.cbegin();
    advance(it, index);
    return *it;
}

Classroom Timetable::findClassroomById(int id) const 
{
    // Parcourir les classrooms avec un itérateur
    Classroom search(id, "", 0);
    auto it = classrooms.find(search);
    return *it; // Retourner l'objet trouvé
}

Professor Timetable::findProfessorByIndex(int index) const 
{
    auto it = professors.cbegin();
    advance(it, index);
    return *it;
}

Professor Timetable::findProfessorById(int id) const 
{
    // Parcourir les classrooms avec un itérateur
    Professor search(id, "", "");
    auto it = professors.find(search);
    return *it; // Retourner l'objet trouvé
}

Group Timetable::findGroupByIndex(int index) const 
{
    auto it = groups.cbegin();
    advance(it, index);
    return *it;
}

Group Timetable::findGroupById(int id) const 
{
    // Parcourir les classrooms avec un itérateur
    Group g(id, "");
    auto it = groups.find(g);
    return *it; // Retourner l'objet trouvé
}

// Display 
void Timetable::displayClassrooms() const {
    for (set<Classroom>::const_iterator it = classrooms.cbegin() ; it != classrooms.cend() ; it++) 
    {
        cout << "-->" << it->toString() << endl;
    }
}

void Timetable::displayProfessors() const {
    for (set<Professor>::const_iterator it = professors.cbegin() ; it != professors.cend() ; it++) 
    {
        cout << "-->" << it->toString() << endl;
    }
}

void Timetable::displayGroups() const {
    for (set<Group>::const_iterator it = groups.cbegin() ; it != groups.cend() ; it++) 
    {
        cout << "-->" << it->toString() << endl;
    }
}

// Delete 
void Timetable::deleteClassroomByIndex(int index) {
    auto it = classrooms.begin();
    advance(it, index);
    classrooms.erase(it);
}

void Timetable::deleteClassroomById(int id) {
    for (auto it = classrooms.begin(); it != classrooms.end(); ++it) {
        if (it->getId() == id) {
            classrooms.erase(it);
            return;
        }
    }
}

void Timetable::deleteProfessorByIndex(int index) {
    auto it = professors.begin();
    advance(it, index);
    professors.erase(it);
}

void Timetable::deleteProfessorById(int id) {
    for (auto it = professors.begin(); it != professors.end(); ++it) {
        if (it->getId() == id) {
            professors.erase(it);
            return;
        }
    }
}

void Timetable::deleteGroupByIndex(int index) {
    auto it = groups.begin();
    advance(it, index);
    groups.erase(it);
}

void Timetable::deleteGroupById(int id) {
    for (auto it = groups.begin(); it != groups.end(); ++it) {
        if (it->getId() == id) {
            groups.erase(it);
            return;
        }
    }
}
