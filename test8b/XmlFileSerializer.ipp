#include "XmlFileSerializer.hpp"
#include <stdexcept>
#include <sstream>

template <typename T>
const char XmlFileSerializer<T>::READ = 'R';

template <typename T>
const char XmlFileSerializer<T>::WRITE = 'W';

template<typename T>
XmlFileSerializer<T>::XmlFileSerializer(const string &fn, char m, const string& cn)
  {
    filename = fn;
    mode = m;
    collectionName = cn;

    if(isWritable())
    {
      file.open(filename, ios::out | ios::trunc);
      file << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
      file << "<" << collectionName << ">" << endl;
    }
    else if(isReadable())
    {
      string str;

      file.open(filename, ios::in);
      if(!file)
      {
        throw XmlFileSerializerException(XmlFileSerializerException::FILE_NOT_FOUND, "Fichier non trouvé");
      }
      getline(file, str);
      getline(file, str);
      collectionName = str.substr(1, str.length() -2);
    }
  }
////////////////////////////////////////////////////////////////////
template<typename T> 
XmlFileSerializer<T>::~XmlFileSerializer()
  {
    if(isWritable())
    {
      file << "</" << collectionName << ">\n";
    }
    file.close();
  }
////////////////////////////////////////////////////////////////////
template<typename T>
string XmlFileSerializer<T>::getFilename() const
  {
    return filename;
  }

template<typename T>
string XmlFileSerializer<T>::getCollectionName() const
  {
    return collectionName;
  }
////////////////////////////////////////////////////////////////////
template<typename T>
bool XmlFileSerializer<T>::isReadable() const
  {
    if(mode == READ)
    {
      return true;
    }

    //throw XmlFileSerializerException("Ouverture READ non valide en WRITE", XmlFileSerializerException::NOT_ALLOWED);
    return false;
  }

template<typename T>
bool XmlFileSerializer<T>::isWritable() const
  {
    if(mode == WRITE)
    {
      return true;
    }
    //throw XmlFileSerializerException("Ouverture WRITE non valide en READ", XmlFileSerializerException::NOT_ALLOWED);
    return false;
  }
////////////////////////////////////////////////////////////////////
template<typename T>
void XmlFileSerializer<T>::write(const T& val)
  {
    if(isWritable())
    {
      file << val << endl;
    }
    else
    {
      throw XmlFileSerializerException(XmlFileSerializerException::NOT_ALLOWED, "Tentative de D'écriture en mode Lecture");      
    }
  }

template<typename T>
T XmlFileSerializer<T>::read()
  {
    if(isReadable())
    {
      string colnam;

      int position = file.tellg();

      file >> colnam;
      
      if(colnam == ("</" + collectionName + ">"))
      {
        throw XmlFileSerializerException(XmlFileSerializerException::END_OF_FILE, "Fin du fichier");
      }
      file.seekg(position);
      T val;
      file >> val;
      return val;
    }
    else
    {
      throw XmlFileSerializerException(XmlFileSerializerException::NOT_ALLOWED, "Tentative de Lecture en mode Ecriture");
    }
  }