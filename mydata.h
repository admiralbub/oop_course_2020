#ifndef MYDATA_H
#define MYDATA_H

#include <QFile>
#include <QTextStream>
#include <QString>

class MyData
{
public:
    MyData();
    MyData(int number_questions);
    QFile file;
    QTextStream stream;
    int counter_question;
    int getNumberAlQuestions();
    void initFileAndOpenForRead(QString name_file);
private:
    int number_all_questions;
};
#endif // MYDATA_H
