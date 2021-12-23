#include "filesysteminterface.h"

FileSystemInterface::FileSystemInterface()
{
    this->init();
}

void FileSystemInterface::init()
{
    if (!this->testConfigFileExist()) {
        this->writeDefaultConfigFile();
    }
    this->loadFromFile();
}

Config *FileSystemInterface::loadFromFile()
{
    QFile file("config-orc.json");
    Config *config = nullptr;

    if( file.open( QIODevice::ReadOnly ) )
    {
        QByteArray bytes = file.readAll();
        file.close();

        QJsonParseError jsonError;
        QJsonDocument document = QJsonDocument::fromJson( bytes, &jsonError );

        if( jsonError.error != QJsonParseError::NoError )
        {
            std::cout << "fromJson failed: " << jsonError.errorString().toStdString() << std::endl;
        }
        if( document.isObject() )
        {
            QJsonObject jsonObj = document.object();
            QJsonObject *ptrJsonObj = new QJsonObject(jsonObj);
            config = new Config(ptrJsonObj);
            return config;
        } else {
            config = new Config();
        }
    }
    return config;
}

bool FileSystemInterface::testConfigFileExist()
{
    bool exist = false;
    QString fileName("config-orc.json");
    QFile file(fileName);

    if (file.exists()) {
        exist = true;
    }
    return exist;
}

void FileSystemInterface::writeDefaultConfigFile()
{
    QString defaultConfigFile = "{"
                                "\"network-config\": {\"ip\": \"192.168.1.1\",\"port\": \"8080\"},"
                                "\"ui-config\": {"
                                    "\"color\": {"
                                        "\"button\": \"#cecece\","
                                        "\"background\": \"#aeaeae\""
                                  "},"
                                  "\"tooltip\":\"false\","
                                  "\"sortcut\": {"
                                    "\"0\": \"0\","
                                    "\"1\": \"1\","
                                    "\"2\": \"2\","
                                    "\"3\": \"3\","
                                    "\"4\": \"4\","
                                    "\"5\": \"5\","
                                    "\"6\": \"6\","
                                    "\"7\": \"7\","
                                    "\"8\": \"8\","
                                    "\"9\": \"9\","
                                    "\"onoff\": \"O\","
                                    "\"settings\": \"P\","
                                    "\"netflix\": \"N\","
                                    "\"up\": \"Z\","
                                    "\"left\": \"Q\","
                                    "\"ok\": \"E\","
                                    "\"right\": \"D\","
                                    "\"down\": \"S\","
                                    "\"menu\": \"M\","
                                    "\"back\": \"Backspace\","
                                    "\"voldown\": \"Down\","
                                    "\"mute\": \"T\","
                                    "\"volup\": \"Up\","
                                    "\"backward\": \"Left\","
                                    "\"playpause\": \"Space\","
                                    "\"foreward\": \"Right\""
                                  "}"
                                "}"
                              "}";

    std::ofstream outputFile;
    outputFile.open("config-orc.json");
    outputFile << defaultConfigFile.toStdString();
    outputFile.close();
}

void FileSystemInterface::save(Config *config)
{

}

void FileSystemInterface::save(QJsonObject *jsonObject)
{
    QJsonDocument tempDocument = QJsonDocument(*jsonObject);
    QByteArray bytes = tempDocument.toJson( QJsonDocument::Indented );
    QFile file("config-orc.json");
    if( file.open( QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate ) )
    {
        QTextStream iStream( &file );
        iStream << bytes;
        file.close();
    }
    else
    {
        std::cout << "file open failed: " << "config-orc.json" << std::endl;
    }
}

FileSystemInterface::~FileSystemInterface()
{

}
