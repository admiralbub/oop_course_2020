#include "mydata.h"

MyData::MyData()
{

}

void MyData::initFileAndOpenForRead(QString name_file)
{
    file.setFileName(name_file);
    file.open(QIODevice::ReadOnly);
    stream.setDevice(&file);
}
