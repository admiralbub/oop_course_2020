#include "mydata.h"

void XML_Data::Init_xml_file_read(QString name_file)
{
    Init_xml_file(name_file);
    xml_stream_read.setDevice(&file_xml);
    file_xml.open(QIODevice::ReadOnly);
}

void XML_Data::Init_xml_file(QString name_file)
{
    file_xml.setFileName(name_file);
}

void XML_Data::Init_xml_file_write(QString name_file)
{
    xml_stream.setDevice(&file_xml);
    Init_xml_file(name_file);
    file_xml.open(QIODevice::WriteOnly);
}

void MyData::Write_Answer_in_file(QString name, QString result)
{
     xml_stream.writeCharacters("\t");
     xml_stream.writeStartElement("result");
     xml_stream.writeAttribute("name", name);
     xml_stream.writeCharacters(result);
     xml_stream.writeEndElement();
     xml_stream.writeCharacters("\n");
}

void MyData::Write_Root_Element()
{
    xml_stream.writeStartDocument();     // Запускаем запись в документ
    xml_stream.writeCharacters("\n");
    xml_stream.writeStartElement("Info");
    xml_stream.writeCharacters("\n");
}

void MyData::Write_End_Root_Element()
{
    xml_stream.writeEndElement();        // Закрываем тег
    file_xml.close();
}

MyData::MyData()
{

}

MyData::MyData(int number_questions)
{
    counter_question = 0;
    this->number_all_questions = number_questions;
}

void MyData::InitFile (QString name_file)
{
    file.setFileName(name_file);
    stream.setDevice(&file);
}

void MyData::OpenForRead(QFile &q, QString name_file)
{
    InitFile(name_file);
    q.open(QIODevice::ReadOnly);
}

void MyData::OpenForWrite(QFile &q, QString name_file)
{
    InitFile(name_file);
    q.open(QIODevice::WriteOnly);
}

int MyData::getNumberAlQuestions()
{
    return number_all_questions;
}

void MyData::CloseFile()
{
    stream.seek(0);
    file.close();
    file_xml.close();
}
