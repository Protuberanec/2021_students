#include <QCoreApplication>
#include <QDebug>
#include <QString>

#include    <QFile>
#include "fifo.h"
#include "workfile.h"

int main(int argc, char *argv[])
{

    WorkFile *wf = new WorkFile();
    wf->ShowFile();

    elements max = wf->ReturnMaxElement();
    qDebug() << (int)max.symbol << "\"" << max.symbol << "\"" << " " << max.freq;




    return 0;   //uncomment

    char tempss[256];
    tempss['a'] = 100;

    qDebug() << tempss['a'] << " " << (unsigned int)tempss['a'];


    my_fifo *test;

    test = new my_fifo(16);

    for (int i = 0; i < 24; i++) {
        if (test->push(i + 1)) {
            continue;
        }
        break;
    }

    int el_fifo;

//    test->flush();

    while(test->pop(&el_fifo)) {
        qDebug() << QString("pop 0x%1").arg(el_fifo, 2, 16, QLatin1Char('0')) << " : " << el_fifo;
    }


    for (int i = 0; i < 20; i++) {
        if (!test->pop(&el_fifo)) {
            qDebug() << "buffer is empty";
            break;
        }

        qDebug() << QString("pop 0x%1").arg(i, 2, 16, QLatin1Char('0')) << " : " << el_fifo;
        if (el_fifo != i) {
            break;
        }

    }


    delete test;


    return 0;
}
