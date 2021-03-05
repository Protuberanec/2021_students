#ifndef LOG_H
#define LOG_H

#include    <QFile>
#include    <QTime>
#include    <QString>
#include    <QDebug>

class LOG
{
private :
    QFile *log_file;

public:
    LOG();
    LOG(QString log_name);

    ~LOG();

    void WriteLog(QString str);
};

#endif // LOG_H
