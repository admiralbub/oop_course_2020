#ifndef MYDATA_H
#define MYDATA_H

#include <QFile>
#include <QTextStream>
#include <QString>
#include <QXmlStreamWriter>

class XML_Data
{
public:
    QXmlStreamWriter xml_stream;
    QFile file_xml;
    void Write_Answer_in_file();
    void Init_xml_file(QString name_file);
};

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
    void CloseFile();
private:
    int number_all_questions;
    void InitFile(QString name_file);
};

#endif // MYDATA_H
