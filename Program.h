#ifndef PROGRAM_H
#define PROGRAM_H

#include <string>
#include <sstream>

class Program {

private:
    std::string name;
    int duration;
    int temperature;
    float energyConsumption;

public:
    Program(std::string, int, int, float);
    std::string getName();
    std::string toString();
    friend class Dishwasher;
};

#endif
