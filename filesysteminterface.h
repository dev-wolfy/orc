#ifndef FILESYSTEMINTERFACE_H
#define FILESYSTEMINTERFACE_H

#include <QJsonParseError>
#include <iostream>
#include <fstream>
#include <QFile>

#include <config.h>

class FileSystemInterface
{
public:
    FileSystemInterface();

    void init();
    Config *loadFromFile();
    bool testConfigFileExist();
    void writeDefaultConfigFile();

    void save(Config *config);
    void save(QJsonObject *jsonObject);

    ~FileSystemInterface();
};

#endif // FILESYSTEMINTERFACE_H
