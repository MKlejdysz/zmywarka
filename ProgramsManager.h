#ifndef PROGRAMSMANAGER_H
#define PROGRAMSMANAGER_H

#include <fstream>
#include <iostream>
#include <vector>
#include "Program.h"

class ProgramsManager {

private:
    std::string sourceFileName;
    std::vector<Program*> programs;

public:
    ProgramsManager(const std::string);
    ~ProgramsManager();
    int getSize() const;
    void readPrograms();
    Program* getProgram(int);
    std::vector<std::string> getNames() const;
};


#endif
