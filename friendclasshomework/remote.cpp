#include "Remote.h"
#include "TV.h"

Remote::Remote(TV* tv)
{
    this->tv = tv;
}

void Remote::chooseTV(TV* tv)
{
    this->tv = tv;
}

void Remote::power()
{
    tv->power();
}

Remote& Remote::operator++()
{
    tv->nextChannel();
    return *this;
}

Remote Remote::operator++(int)
{
    Remote temp = *this;
    tv->nextChannel();
    return temp;
}

Remote& Remote::operator--()
{
    tv->prevChannel();
    return *this;
}

Remote Remote::operator--(int)
{
    Remote temp = *this;
    tv->prevChannel();
    return temp;
}

void Remote::operator+() const
{
    tv->incVolume();
}

void Remote::operator-() const
{
    tv->decVolume();
}

void Remote::goChannel(size_t ch)
{
    if (!tv->status) return;
    if (ch >= 1 && ch <= tv->maxChannel)
        tv->channel = ch;
}