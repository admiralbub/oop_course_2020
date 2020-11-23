#include "mydata.h"
#include "myexception.h"

void XML_Data::Init_xml_file_read(QString name_file)
{
    Init_xml_file(name_file);
    xml_stream_read.setDevice(&file_xml);
    if (!file_xml.open(QIODevice::ReadOnly)){
        pMyException->throwException(QString("Не смогли отрыть файл %1 для чтения").arg(name_file), QString (Q_FUNC_INFO));
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
        pMyException->throwException(QString("Не смогли отрыть файл %1 для записи").arg(name_file), QString (Q_FUNC_INFO));
    }
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
    xml_stream.writeStartElement("info");
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
    if (!q.open(QIODevice::ReadOnly)){
        pMyException->throwException(QString("Не смогли отрыть файл %1 для чтения").arg(name_file), QString (Q_FUNC_INFO));
    }
}

void MyData::OpenForWrite(QFile &q, QString name_file)
{
    InitFile(name_file);
    if (!q.open(QIODevice::WriteOnly)){
        pMyException->throwException(QString("Не смогли отрыть файл %1 для записи").arg(name_file), QString (Q_FUNC_INFO));
    }
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
