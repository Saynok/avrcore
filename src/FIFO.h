#ifndef FIFO_H
#define FIFO_H

#include <stdint.h>

class FIFO
{
public:
    void put(uint8_t value);
    uint8_t get();
    uint16_t getLength();

private:
    uint8_t buffer[256];
    uint16_t length = 0;
    uint16_t startIndex= 0;
    uint16_t endIndex = 0;
};

#endif