#include "TV.h"
#include <iostream>
using namespace std;

TV::TV(size_t channel, size_t volume, bool status, size_t maxChannel, size_t maxVolume)
    : maxChannel(maxChannel), maxVolume(maxVolume)
{
    this->channel = channel;
    this->volume = volume;
    this->status = status;
}

void TV::power()
{
    status = !status;
}

void TV::nextChannel()
{
    if (!status) return;
    if (channel + 1 > maxChannel)
        channel = 1;
    else
        ++channel;
}

void TV::prevChannel()
{
    if (!status) return;
    if (channel - 1 < 1)
        channel = maxChannel;
    else
        --channel;
}

void TV::incVolume()
{
    if (!status) return;
    if (volume + 1 <= maxVolume)
        ++volume;
}

void TV::decVolume()
{
    if (!status) return;
    if (volume - 1 >= 1)
        --volume;
}

void TV::printInfo() const
{
    cout << "TV :: " << (status ? "ON" : "OFF")
        << ", active channel: " << channel
        << ", volume: " << volume << endl;
}