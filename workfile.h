#ifndef WORKFILE_H
#define WORKFILE_H

#include    <QFile>
#include    <QString>
#include    <QDebug>
#include    <QByteArray>

struct elements {
    int freq {0};
    char symbol {0};

    elements() {}
    elements(int f, char s) : freq(f), symbol(s) {}
};

class WorkFile
{
    private :
        QFile stat_file;
        char *content_text_file {NULL};//        QByteArray;
        int size {0};

        int freq_symbol[256];

        void ReadTextFile();
        void CreateStatInfo();


    public:
        WorkFile();
        WorkFile(QString file_name);
        ~WorkFile();

        void ShowFile();
        struct elements ReturnMaxElement();


};



#endif // WORKFILE_H
