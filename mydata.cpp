#include "mydata.h"

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

void MyData::OpenForRead(QString name_file)
{
    InitFile(name_file);
    file.open(QIODevice::ReadOnly);
}

void MyData::OpenForWrite(QString name_file)
{
    InitFile(name_file);
    file.open(QIODevice::WriteOnly);
}

int MyData::getNumberAlQuestions()
{
    return number_all_questions;
}

void MyData::CloseFile()
{
    stream.seek(0);
    file.close();
}
