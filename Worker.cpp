#include "Worker.h"

using namespace std;

Worker::Worker(int timer) {
    this->timer = timer;
}

void Worker::runProgram() {
    running = true;
    while (running && timer > 0) {
        if (!paused) {
            int minutes = timer % 60;
            string minutesStr = (timer % 60) < 10 ? "0" + minutes : to_string(minutes);
            cout << "Remaining: " << (timer / 60) << ":" << minutes << endl;
            timer--;
        }
        this_thread::sleep_for(chrono::milliseconds(995));
    }
    running = false;

    if (timer == 0)
        cout << "Washing has ended, press enter to exit" << endl;
}
