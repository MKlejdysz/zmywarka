#ifndef WORKER_H
#define WORKER_H

#include <atomic>
#include <chrono>
#include <iostream>
#include <string>
#include <thread>

class Worker {

private:
    int timer;
    bool paused = false;
    std::atomic_bool running{ false };

public:
    Worker(int);
    void runProgram();
    int getRemaining() { return timer; }
    void stopProgram() { running = false; }
    void pauseProgram() { paused = true; }
    void resumeProgram() { paused = false; }
    bool isRunning() { return running; }
};

#endif