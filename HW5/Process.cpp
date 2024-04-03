//csv file with Process ID(string), arrival time(int), burst duration(int()), priority(from 1(high)-50(low))
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

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
}   
