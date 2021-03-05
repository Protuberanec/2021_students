#ifndef FIFO_H
#define FIFO_H

#include "log.h"

class FIFO
{
private :
    LOG *log_fifo;
    int *arr;
    int size;
    int amount_el;

    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

public:

    FIFO();
    FIFO(int new_size);
    ~FIFO();

    void flush();
    int push(int el);
    int pop(int *el);
    int resize(int new_size);
    int getAmount_el() const;
};

using my_fifo = class FIFO;

#endif // FIFO_H
