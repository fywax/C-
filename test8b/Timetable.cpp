#include "Timetable.h"
#include "schedulable.h"
#include <iostream>

// Initialisation de l'instance statique
Timetable* Timetable::instance = nullptr;

// Constructeur privé
Timetable::Timetable() {
    // Initialisation si nécessaire
}

// Destructeur privé
Timetable::~Timetable() {
    // Libération des ressources si nécessaire
}

// Méthode statique pour obtenir l'instance unique
Timetable& Timetable::getInstance() {
    if (instance == nullptr) {
        instance = new Timetable();
    }
    return *instance;
}

// Méthode pour ajouter une salle de classe
int Timetable::addClassroom(const std::string& name, int seatingCapacity) {
    Schedulable::currentId += 1;
    Classroom c(Schedulable::currentId, name, seatingCapacity);

    auto result = classrooms.insert(c);
    if (!result.second) {
        std::cout << "La salle existe déjà" << std::endl;
        return -1;
    }

    return Schedulable::currentId;
}

// Méthode pour afficher les salles de classe
void Timetable::displayClassrooms() const {
    for (const auto& classroom : classrooms) {
        std::cout << "-->" << classroom.toString() << std::endl;
    }
}

// Méthode pour trouver une salle de classe par index
Classroom Timetable::findClassroomByIndex(int index) const {
    if (index < 0 || index >= classrooms.size()) {
        std::cerr << "Index hors limites." << std::endl;
        return Classroom(-1, "Invalid", 0);
    }

    auto it = classrooms.cbegin();
    std::advance(it, index);
    return *it;
}

// Méthode pour trouver une salle de classe par ID
Classroom Timetable::findClassroomById(int id) const {
    Classroom search(id, "", 0);
    auto it = classrooms.find(search);

    if (it == classrooms.end()) {
        std::cerr << "Salle de classe introuvable." << std::endl;
        return Classroom(-1, "Invalid", 0);
    }

    return *it;
}

// Méthode pour supprimer une salle de classe par index
void Timetable::deleteClassroomByIndex(int index) {
    if (index < 0 || index >= classrooms.size()) {
        std::cerr << "Index hors limites." << std::endl;
        return;
    }

    auto it = classrooms.begin();
    std::advance(it, index);
    classrooms.erase(it);
}

// Méthode pour supprimer une salle de classe par ID
void Timetable::deleteClassroomById(int id) {
    Classroom search(id, "", 0);
    auto it = classrooms.find(search);

    if (it == classrooms.end()) {
        std::cerr << "Salle de classe introuvable ou déjà supprimée." << std::endl;
        return;
    }

    classrooms.erase(it);
}

// Méthode pour ajouter un professeur
int Timetable::addProfessor(const std::string& lastName, const std::string& firstName) {
    Schedulable::currentId += 1;
    Professor p(Schedulable::currentId, lastName, firstName);

    auto result = professors.insert(p);
    if (!result.second) {
        std::cout << "Le professeur existe déjà." << std::endl;
        return -1;
    }

    return Schedulable::currentId;
}

// Méthode pour afficher les professeurs
void Timetable::displayProfessors() const {
    for (const auto& professor : professors) {
        std::cout << "-->" << professor.toString() << std::endl;
    }
}

// Méthode pour trouver un professeur par index
Professor Timetable::findProfessorByIndex(int index) const {
    if (index < 0 || index >= professors.size()) {
        std::cerr << "Index hors limites." << std::endl;
        return Professor(-1, "Invalid", "");
    }

    auto it = professors.cbegin();
    std::advance(it, index);
    return *it;
}

// Méthode pour trouver un professeur par ID
Professor Timetable::findProfessorById(int id) const {
    Professor search(id, "", "");
    auto it = professors.find(search);

    if (it == professors.end()) {
        std::cerr << "Professeur introuvable." << std::endl;
        return Professor(-1, "Invalid", "");
    }

    return *it;
}

// Méthode pour supprimer un professeur par index
void Timetable::deleteProfessorByIndex(int index) {
    if (index < 0 || index >= professors.size()) {
        std::cerr << "Index hors limites." << std::endl;
        return;
    }

    auto it = professors.begin();
    std::advance(it, index);
    professors.erase(it);
}

// Méthode pour supprimer un professeur par ID
void Timetable::deleteProfessorById(int id) {
    Professor search(id, "", "");
    auto it = professors.find(search);

    if (it == professors.end()) {
        std::cerr << "Professeur introuvable ou déjà supprimé." << std::endl;
        return;
    }

    professors.erase(it);
}

// Méthode pour ajouter un groupe
int Timetable::addGroup(const std::string& name) {
    Schedulable::currentId += 1;
    Group g(Schedulable::currentId, name);

    auto result = groups.insert(g);
    if (!result.second) {
        std::cout << "Le groupe existe déjà." << std::endl;
        return -1;
    }

    return Schedulable::currentId;
}

// Méthode pour afficher les groupes
void Timetable::displayGroups() const {
    for (const auto& group : groups) {
        std::cout << "-->" << group.toString() << std::endl;
    }
}

// Méthode pour trouver un groupe par index
Group Timetable::findGroupByIndex(int index) const {
    if (index < 0 || index >= groups.size()) {
        std::cerr << "Index hors limites." << std::endl;
        return Group(-1, "Invalid");
    }

    auto it = groups.cbegin();
    std::advance(it, index);
    return *it;
}

// Méthode pour trouver un groupe par ID
Group Timetable::findGroupById(int id) const {
    Group search(id, "");
    auto it = groups.find(search);

    if (it == groups.end()) {
        std::cerr << "Groupe introuvable." << std::endl;
        return Group(-1, "Invalid");
    }

    return *it;
}

// Méthode pour supprimer un groupe par index
void Timetable::deleteGroupByIndex(int index) {
    if (index < 0 || index >= groups.size()) {
        std::cerr << "Index hors limites." << std::endl;
        return;
    }

    auto it = groups.begin();
    std::advance(it, index);
    groups.erase(it);
}

// Méthode pour supprimer un groupe par ID
void Timetable::deleteGroupById(int id) {
    Group search(id, "");
    auto it = groups.find(search);

    if (it == groups.end()) {
        std::cerr << "Groupe introuvable ou déjà supprimé." << std::endl;
        return;
    }

    groups.erase(it);
}