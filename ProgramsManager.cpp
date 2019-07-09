#include "ProgramsManager.h"

using namespace std;

ProgramsManager::ProgramsManager(string sourceFileName) {
    this->sourceFileName = sourceFileName;
}

ProgramsManager::~ProgramsManager() {
    for (auto* program : programs) {
        delete program;
    }
}

void ProgramsManager::readPrograms() {
    
    ifstream input;
    input.open(sourceFileName);
    if (!input) {
        cerr << "Could not open file or it does not exist" << endl;
    }
    string str;
    getline(input, str);
    int size = stoi(str);

    for (int i = 0; i < size; i++) {
        getline(input, str);
        string name = str;
        getline(input, str);
        istringstream iss(str);
        int length, temperature;
        float enrgCons;
        iss >> length >> temperature >> enrgCons;
        
        Program* program = new Program(name, length, temperature, enrgCons);
        programs.push_back(program);
    }
    input.close();
}

Program* ProgramsManager::getProgram(int id) {
    if (id > programs.size() - 1 || id < 0) {
        return nullptr;
    }
    return programs[id];
}

vector<string> ProgramsManager::getNames() const {
    vector<string> names;
    for (auto* program : programs) {
        names.push_back(program->getName());
    }
    return names;
}

int ProgramsManager::getSize() const {
    return (int) programs.size();
}
