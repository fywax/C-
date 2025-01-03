#ifndef XML_FILE_SERIALIZER_HPP
#define XML_FILE_SERIALIZER_HPP

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "XmlFileSerializerException.h"

using namespace std;

template <typename T>
class XmlFileSerializer {
    private:
        fstream file; //lien avec fich sr disque
        string filename;//nom fich
        char mode;//mode ouverture fich (read ou write)
        string collectionName;//pr mettre les nom de collections (pr exemple times si que des Time)

    public:
        static const char READ;
        static const char WRITE;

        XmlFileSerializer() = delete;//pr éviter ouverture excessive
        XmlFileSerializer(const string &fn, char m, const string& cn = "entities");//entities = val par def
        XmlFileSerializer(const XmlFileSerializer& cop) = delete;//pr éviter ouverture excessive
        ~XmlFileSerializer();

        XmlFileSerializer& operator=(const XmlFileSerializer& t) = delete;//pr éviter ouverture excessive

        //pas de set pour variable membre
        //elles sont fixées définitivement par le constructeur

        void write(const T& val);//sérialiser
        T read();//désérialiser

        string getFilename() const;
        string getCollectionName() const;
        bool isWritable()const;
        bool isReadable()const;
};

#include "XmlFileSerializer.ipp"

#endif // XML_FILE_SERIALIZER_HPP
