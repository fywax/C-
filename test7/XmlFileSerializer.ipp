#ifndef XML_FILE_SERIALIZER_IPP
#define XML_FILE_SERIALIZER_IPP

#include <stdexcept>

template <typename T>
char const XmlFileSerializer<T>::READ = 'R';

template <typename T>
char const XmlFileSerializer<T>::WRITE = 'W';

template <typename T>
XmlFileSerializer<T>::XmlFileSerializer(const string& fn, char m, const string& cn)
{
    this->filename = fn;
    this->collectionName = cn;
    this->mode = m;

    if(strcmp(m, READ) && strcmp(m, WRITE))
    {
        cerr << mode << " n'est pas un mode valide. Utilisez 'R' (lecture) ou 'W' (écriture)." << endl;
    }
}


template <typename T>
XmlFileSerializer<T>::~XmlFileSerializer()
{
    if (file.is_open()) 
    {
        if (mode == WRITE) 
        {
            file << "</" << this->collectionName << ">" << endl; // Écrire la balise de fermeture
        }
        file.close(); // Fermer le fichier
    }
}

template <typename T>
void XmlFileSerializer<T>::write(const T& val)
{
    if(strcmp(this->mode, WRITE))
    {    
        file.open(filename, ios::out | ios::trunc);
            
        if (!file.is_open()) 
        {
            cerr << "Erreur d'ouverture du fichier en écriture : " << filename << endl;
            return;
        }
        
        file << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
        file << "<" << collectionName << ">" << endl;
    }
    else
    {
        cerr << this->filename << " n'est pas en mode écriture" << endl;
    }
}

template <typename T>
T XmlFileSerializer<T>::read()
{
    if(strcmp(this->mode, READ))
    {
        file.open(filename, ios::in);
    
        if (!file.is_open()) 
        {
            cerr << "Erreur d'ouverture du fichier en lecture : " << filename << endl;
            return;
        }
    
        string line;
        for (int i = 0; i < 2; i++) 
        {
            getline(file, line);
    
            if (i == 1) // Lecture de la deuxième ligne (balise de collection)
            { 
                size_t start = line.find("<") + 1;
                size_t end = line.find(">");
                if (start != string::npos && end != string::npos && start < end) 
                {
                    collectionName = line.substr(start, end - start); // Extraire le nom de la collection
                    cout << "Nom de la collection extrait : " << collectionName << endl;
                } 
                else 
                {
                    cerr << "Erreur : Balise de début de collection introuvable." << endl;
                }
                break;
            }
        }
    }
}

template <typename T>
string XmlFileSerializer<T>::getFilename() const
{
    return this->filename;
}

template <typename T>
string XmlFileSerializer<T>::getCollectionName() const
{
    return this->collectionName;
}

template<typename T>
bool XmlFileSerializer<T>::isWritable() const {
    // Vérifie si le mode est WRITE et si le fichier est ouvert
    return (mode == WRITE) && file.is_open() && file.good();
}

template<typename T>
bool XmlFileSerializer<T>::isReadable() const {
    // Vérifie si le mode est READ et si le fichier est ouvert
    return (mode == READ) && file.is_open() && file.good();
}

#endif // XML_FILE_SERIALIZER_IPP
