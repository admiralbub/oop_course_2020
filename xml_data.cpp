#include "xml_data.h"

void XML_Data::Init_xml_file_read(QString name_file)
{
    Init_xml_file(name_file);
    xml_stream_read.setDevice(&file_xml);
    if (!file_xml.open(QIODevice::ReadOnly)){
       throw (MyException(QString("Не змогли відкрити файл %1 для читання").arg(name_file), QString (Q_FUNC_INFO)));
    }
}

void XML_Data::Init_xml_file(QString name_file)
{
    file_xml.setFileName(name_file);
}

void XML_Data::Init_xml_file_write(QString name_file)
{
    xml_stream.setDevice(&file_xml);
    Init_xml_file(name_file);
    if (!file_xml.open(QIODevice::WriteOnly)){
        throw (MyException(QString("Не змогли відкрити файл %1 для запису").arg(name_file), QString (Q_FUNC_INFO)));
    }
}
