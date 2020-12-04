#ifndef XML_DATA_H
#define XML_DATA_H

#include <QFile>
#include <QString>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include "myexception.h"

class XML_Data
{
public:
    QXmlStreamWriter xml_stream;
    QXmlStreamReader xml_stream_read;
    QFile file_xml;
    void Init_xml_file_write(QString name_file);
    void Init_xml_file_read(QString name_file);
private:
    void Init_xml_file(QString name_file);
};

#endif // XML_DATA_H
