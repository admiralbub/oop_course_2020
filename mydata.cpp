#include "mydata.h"

MyData::MyData()
{

}

MyData::MyData(int number_questions)
{
    counter_question = 0;
    this->number_all_questions = number_questions;
}

void MyData::initFileAndOpenForRead(QString name_file)
{
    file.setFileName(name_file);
    file.open(QIODevice::ReadOnly);
    stream.setDevice(&file);
}

int MyData::getNumberAlQuestions()
{
    return number_all_questions;
}
