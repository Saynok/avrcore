#include "FIFO.h"

void FIFO::put(uint8_t value)
{

    buffer[endIndex] = value;

    //shifting
    if (length == sizeof(buffer))
    {
        startIndex++;
        endIndex++;
    }
    else
    {
        length++;
        endIndex++;
    }

    if (startIndex == sizeof(buffer))
        startIndex = 0;
    if (endIndex == sizeof(buffer))
        endIndex = 0;
}

uint8_t FIFO::get()
{
    uint8_t value = buffer[startIndex];

    if (length > 0)
    {
        startIndex++;
        length--;
        if (startIndex == sizeof(buffer))
            startIndex = 0;
    }

    return value;
}

uint16_t FIFO::getLength()
{
    return length;
}
