#include "TV.h"
#include "Remote.h"

int main()
{
    TV tv1(20, 30, false, 50, 30);
    tv1.power();
    tv1.printInfo(); 

    Remote remote(&tv1);
    +remote;
    tv1.printInfo(); 

    ++remote;
    tv1.printInfo(); 

    --remote;
    tv1.printInfo(); 

    remote.goChannel(10);
    tv1.printInfo(); 

    TV tv2(5, 10);
    remote.chooseTV(&tv2);
    remote.power();
    +remote;
    tv2.printInfo(); 

}