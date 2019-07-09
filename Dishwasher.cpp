#include "Dishwasher.h"

using namespace std;

Dishwasher::Dishwasher() {
    currentProgram = 0;
    progManager = new ProgramsManager("programs_data.txt");
    progManager->readPrograms();
}

Dishwasher::~Dishwasher() {
    delete progManager;
}

void Dishwasher::startMachine() {
    vector<string> names = progManager->getNames();
    cout << "Programs count: " << names.size() << endl;
    for (int i = 0; i < names.size(); i++) {
        cout << (i + 1) << ": " << names[i] << endl;
    }

    bool selectProgram = true;
    while (selectProgram) {
        cout << "\nSelected program (" << (currentProgram + 1) << "):\n"
            << progManager->getProgram(currentProgram)->toString() << endl;
        cout << "Change selected program? (yes/no)";
        selectProgram = confirmation();
        if (selectProgram) {
            cout << "Choose program number (1-" << names.size() << "): ";
            int val = readNumber();
            currentProgram = val < 1 || val > names.size() ? currentProgram : val - 1;
        }
    }

    cout << "Type 'yes' to start selected program" << endl;
    if (!confirmation())
        return;


    int timer = progManager->getProgram(currentProgram)->duration;
    Worker* worker = new Worker(timer);

    thread thrd(&Worker::runProgram, worker);

    this_thread::sleep_for(chrono::milliseconds(10));
    while (worker->isRunning()) {
        cout << "Write 'pause' to hang program execution" << endl;
        string str;
        getline(cin, str);
        if (worker->getRemaining() > 0 && str == "pause") {
            worker->pauseProgram();
            cout << "Program paused, type 'start' to continue, otherwise program ends" << endl;
            getline(cin, str);
            if (str == "start")
                worker->resumeProgram();
            else
                worker->stopProgram();
        }
    }
    thrd.join();
    delete worker;
    cout << "\nTurning dishwasher off" << endl;
}

int Dishwasher::readNumber() const {

    int x;
    bool reading = true;
    while (reading) {
        string value;
        getline(cin, value);

        try {
            x = stoi(value);
            reading = false;
        } catch (const std::invalid_argument& ex) {
            cout << "Please enter a number" << endl;
        }
    }
    return x;
}

bool Dishwasher::confirmation() const {
    string str;
    getline(cin, str);
    return str == "yes";
}
