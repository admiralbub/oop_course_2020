#include "mydata.h"
#include "myexception.h"

MyData::MyData() {}

MyData::MyData(int number_questions)
{
    counter_question = 0;
    this->number_all_questions = number_questions;
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

void MyData::InitFile (QString name_file)
{
    file.setFileName(name_file);
    stream.setDevice(&file);
}

void MyData::OpenForRead(QFile &q, QString name_file)
{
    InitFile(name_file);
    if (!q.open(QIODevice::ReadOnly))
        throw (MyException(QString("Не смогли открыть файл %1 для чтения").arg(name_file), QString (Q_FUNC_INFO)));
}

void MyData::OpenForWrite(QFile &q, QString name_file)
{
    InitFile(name_file);
    if (!q.open(QIODevice::WriteOnly))
        throw (MyException(QString("Не смогли открыть файл %1 для записи").arg(name_file), QString (Q_FUNC_INFO)));
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
