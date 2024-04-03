#ifndef PROCESS
#define PROCESS

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Process
{
private:
        string PID{};
        int arrivalTime{};
        int burstDuration{};
        int priority;

public:
    Process(string t_pid, int t_arrivalTime, int t_burstDuration, int t_priority);
    Process(string record);

    string getPID() const { return PID; }
    int getArrivalTime() const { return arrivalTime; }
    int getBurstDuration() const { return burstDuration; }
    int getPriority() const {return priority;}
};
#endif