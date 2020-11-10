#include "mydata.h"

void XML_Data::Init_xml_file (QString name_file)
{
    file_xml.setFileName(name_file);
    xml_stream.setDevice(&file_xml);
    file_xml.open(QIODevice::WriteOnly);
}

void XML_Data::Write_Answer_in_file()
{
    xml_stream.writeStartDocument();     // Запускаем запись в документ
    xml_stream.writeStartElement("list");   // Записываем первый элемент с его именем
    xml_stream.writeStartElement("");  // Записываем тег с именем для первого
    xml_stream.writeAttribute("atribut",("znachenie"));
    xml_stream.writeEndElement();        // Закрываем тег
    file_xml.close();   // Закрываем файл
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
