#ifndef DISHWASHER_H
#define DISHWASHER_H

#include <thread>
#include "Program.h"
#include "ProgramsManager.h"
#include "Worker.h"

class Dishwasher {

private:
    int currentProgram;
    ProgramsManager* progManager;

    int readNumber() const;
    bool confirmation() const;

public:
    Dishwasher();
    ~Dishwasher();
    void startMachine();
};

#endif
