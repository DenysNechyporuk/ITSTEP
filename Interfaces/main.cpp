#include "SmartRemote.h"
#include "TV.h"
#include "AirConditioner.h"

void main()
{
    TV tv;
    AirConditioner ac;
    SmartRemote remote(&tv);

    cout << "--- TV ---" << endl;
    remote.power();
    remote.next();
    remote.next();
    remote.prev();
    remote.plus();
    remote.plus();
    remote.minus();
    remote.showCurrentDevice();

    cout << endl << "--- AirConditioner ---" << endl;
    remote.setDevice(&ac);
    remote.power();
    remote.plus();
    remote.plus();
    remote.minus();
    remote.next();
    remote.next();
    remote.prev();
    remote.showCurrentDevice();
}