#include "Program.h"


Program::Program(std::string name, int duration, int temperature, float energyConsumption) {
    this->name = name;
    this->duration = duration;
    this->temperature = temperature;
    this->energyConsumption = energyConsumption;
}

std::string Program::toString() {
    std::stringstream ss;
    ss << "Program name: " << name << "\nDuration [H:M]: "
        << (duration / 60) << ":" << (duration % 60)
        << "\nTemperature [C]: " << temperature
        << "\nEnergy Consumption [kWh]: " << energyConsumption;
    return ss.str();
}

std::string Program::getName() {
    return name;
}
