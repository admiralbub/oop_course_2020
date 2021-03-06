#ifndef MYDATA_H
#define MYDATA_H

#include <QTextStream>
#include "xml_data.h"

class MyData: public XML_Data
{
public:
    MyData();
    MyData(int number_questions);
    QFile file;
    QTextStream stream;
    int counter_question;
    int getNumberAlQuestions();
    void OpenForRead(QFile &q, QString name_file);
    void OpenForWrite(QFile &q, QString name_file);
    void Write_Answer_in_file(QString name, QString result);
    void Write_Root_Element();
    void Write_End_Root_Element();
    void CloseFile();

private:
    int number_all_questions;
    void InitFile(QString name_file);
};

#endif // MYDATA_H
