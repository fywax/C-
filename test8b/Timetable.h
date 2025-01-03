#ifndef TIMETABLE_H
#define TIMETABLE_H

#include <set>
#include <string>
#include "Classroom.h"
#include "Professor.h"
#include "Group.h"

class Timetable 
{ 
  private: 
    // Conteneurs pour les données
    std::set<Classroom> classrooms; 
    std::set<Professor> professors; 
    std::set<Group> groups; 

    // Constructeur par défaut privé pour empêcher l'instanciation
    Timetable();

    // Destructeur également privé pour éviter sa destruction directe
    ~Timetable();

    // Supprimer le constructeur de copie et l'opérateur d'affectation
    Timetable(const Timetable&) = delete;
    Timetable& operator=(const Timetable&) = delete;

    // Instance unique de la classe
    static Timetable* instance;

  public:
    // Méthode pour obtenir l'unique instance
    static Timetable& getInstance();

    // Méthodes publiques (inchangées)
    int addClassroom(const std::string& name, int seatingCapacity);
    void displayClassrooms() const;
    Classroom findClassroomByIndex(int index) const;
    Classroom findClassroomById(int id) const;
    void deleteClassroomByIndex(int index);
    void deleteClassroomById(int id);

    int addProfessor(const std::string& lastName, const std::string& firstName);
    void displayProfessors() const;
    Professor findProfessorByIndex(int index) const;
    Professor findProfessorById(int id) const;
    void deleteProfessorByIndex(int index);
    void deleteProfessorById(int id);

    int addGroup(const std::string& name);
    void displayGroups() const;
    Group findGroupByIndex(int index) const;
    Group findGroupById(int id) const;
    void deleteGroupByIndex(int index);
    void deleteGroupById(int id);
}; 

#endif