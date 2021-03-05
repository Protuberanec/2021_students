#include "log.h"

LOG::LOG()
{
    log_file = new QFile("temp_log.log");
    if (log_file->open(QIODevice::Append) == false) {
        qDebug() << "log was not created";
    }
}

LOG::LOG(QString log_name) {
    log_file = new QFile(log_name);
    log_file->open(QIODevice::Append);
}

LOG::~LOG() {
    log_file->close();
}

void LOG::WriteLog(QString str)
{
    //time : str.... \n

    QString cur_tim = QTime::currentTime().toString("HH:mm:ss:zzz : ");
    log_file->write(cur_tim.toUtf8());
    log_file->write(str.toUtf8());
    log_file->putChar('\n');    //new string...
}
