#include "fifo.h"

const int DEFAULT_SIZE_ARR = 128;

int FIFO::getAmount_el() const
{
    return amount_el;
}

FIFO::FIFO()// : amount_el(0), size(DEFAULT_SIZE_ARR)
{
    log_fifo = new LOG("my_log.log");
    arr = new int [DEFAULT_SIZE_ARR];
    size = DEFAULT_SIZE_ARR;
    amount_el = 0;
}

FIFO::FIFO(int S)
{
    log_fifo = new LOG("my_log.log");
    arr = new int [S];
    size = S;
    amount_el = 0;
}

FIFO::~FIFO()
{
    delete [] arr;
    delete log_fifo;
}

void FIFO::flush()
{
    amount_el = 0;
    log_fifo->WriteLog("flush buffer");
}

int FIFO::push(int el)
{
    if (amount_el >= size) {
        log_fifo->WriteLog("buffer is full");
        return 0;
    }

    arr[amount_el++] = el;

    log_fifo->WriteLog("byte pushed to fifo");
    return 1;
//    return size - amount_el;
//    return amount_el;
}

int FIFO::pop(int *el)
{
//    for (amount_el == 0)
    if (!amount_el) {
        log_fifo->WriteLog("buffer is empty");
        return 0;
    }

    *el = arr[0];

    for (int i = 1; i < amount_el; i++) {
       swap(arr[i -1], arr[i]);
    }
    --amount_el;
//    return amount_el;

    log_fifo->WriteLog("pop get 1 byte");
    return 1;

}

int FIFO::resize(int new_size)
{
    delete [] arr;
    arr = new int [new_size];
    size = new_size;
    amount_el = 0;
}
