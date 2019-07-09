
#include <iostream>
#include "Dishwasher.h"

using namespace std;

int main()
{
    Dishwasher* dishwasher = new Dishwasher();
    dishwasher->startMachine();
    delete dishwasher;
    return 0;
}




