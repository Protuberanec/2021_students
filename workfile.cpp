#include "workfile.h"

void WorkFile::ReadTextFile()
{
    size = stat_file.size();
    content_text_file = new char [size + 1 /*end*/];
    memset(content_text_file, 0x00, (size + 1) * sizeof(char)); //write zero

    qDebug() << "res read file = " << stat_file.read(content_text_file, size);
}

void WorkFile::CreateStatInfo()
{
    for (int i = 0; i < size; i++) {
        freq_symbol[content_text_file[i]]++;
    }
}

WorkFile::WorkFile() : size(0), content_text_file(NULL)
{
    memset(freq_symbol, 0x00, 256 * sizeof (int));
    stat_file.setFileName("my_log.log");
    stat_file.open(QIODevice::ReadOnly);
    ReadTextFile();
    stat_file.close();

    CreateStatInfo();
}

WorkFile::WorkFile(QString file_name)
{

}

WorkFile::~WorkFile()
{
//    stat_file.close();
    delete [] content_text_file;
}

void WorkFile::ShowFile()
{
    qDebug() << content_text_file;
}

struct elements WorkFile::ReturnMaxElement()
{
    int index = 0;
    for (int i = 1; i < 256; i++) {
        if (freq_symbol[index] < freq_symbol[i]) {
            index = i;
        }
    }

    return elements(freq_symbol[index], index);

}
