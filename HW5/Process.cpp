//csv file with Process ID(string), arrival time(int), burst duration(int()), priority(from 1(high)-50(low))
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

#include "Process.h"

Process::Process(string t_pid, int t_arrivalTime, int t_burstDuration, int t_priority)
    : PID{t_pid}
    , arrivalTime{t_arrivalTime}
    , burstDuration{t_burstDuration}
{
    if ((t_priority > 50) or (t_priority < 1)){
        //Throw an exception 
    }
    priority = t_priority;
    counter = t_burstDuration;
}   

Process::Process(string record){
    stringstream s(record);
    string val1, val2, val3, val4;
    getline(s, val1, ',');
    getline(s, val2, ',');
    getline(s, val3, ',');
    getline(s, val4, ',');
    PID = val1;
    arrivalTime = stoi(val2);
    burstDuration = stoi(val3);
    priority = stoi(val3);
}

bool Process::decrementCounter(){
    --counter;
    return counter == 0;
}
