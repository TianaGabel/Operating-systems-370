#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

//FIXME what is this top thing
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <vector>
#include <sstream> 
#include "Process.h"

using namespace std;

void FirstComeFirstServed(vector<Process> arrivalList, int numLines){
	int clock = 0;
	int turnAroundTime = 0;
	long totalTurnAroundTime = 0;
	int waitingTime = 0;
	long totalWaitingTime = 0;
	for (auto currProcess : arrivalList){
		//Case that no-proces has arrived
		if (clock < currProcess.getArrivalTime()){
			clock = currProcess.getArrivalTime();
		}
		//Same process for every other case
		clock += currProcess.getBurstDuration();
		turnAroundTime = clock - currProcess.getArrivalTime();
		waitingTime = turnAroundTime - currProcess.getArrivalTime();
		totalTurnAroundTime += turnAroundTime;
		totalWaitingTime += waitingTime;
	}
	PrintFormatting("First Come First Served", totalTurnAroundTime, totalWaitingTime, numLines);
	//NOt a class
}

void ShortestJobFirst(int& seconds) {
	//adds one second to current time
	seconds += 1;
}

void Priority(){

}

void PrintFormatting(string algo,long totalTurnAroundTime, long totalWaitingTime, int numLines ){
	float turnAroundTime = totalTurnAroundTime * 1.0 / numLines;
	float waitingTime = totalWaitingTime * 1.0 / numLines;
	float throughput = 1 / turnAroundTime;
	std::cout << "	--- " << algo << " ---" << endl;
	std::cout << "Average Turnaround Time: " << turnAroundTime << endl;
	std::cout << "Average Waiting Time: " << waitingTime << endl;
	std::cout << "Throughput: " << throughput << endl;

}

Process createProcess(string record){
    stringstream s(record);
    string val1;
	int val2, val3, val4;
    getline(s, val1, ',');
    s >> val2;
	s.ignore();
	s >> val3;
	s.ignore();
	s >> val4;
	return Process(val1,val2, val3, val4);
}

int main() {
    string inputFile = "CS370-HW5-Input.csv";
    fstream inputFS (inputFile);

	std::cout << "Trying to open file" << endl;
    //Check if the file is open or not
	if (!inputFS.is_open()) {
		std::cout << "Could not open file" << endl;
		return 1;
	}

	string PID;
	int arrivalTime = 0;

	int numLines=0;
	vector<Process> processList;
	string currLine;
	while (getline (inputFS, currLine, '\n')) {
		std::cout << "Read element" << endl;
		++numLines; //records lines in file

		if (!inputFS.fail()) {
			std::cout << "bruh" << endl;
			Process p = createProcess(currLine);
			std::cout << p.getPID() << " " << p.getArrivalTime() << " " << p.getBurstDuration() << " " << p.getPriority() << endl;
			if (processList.empty()){
				//First item added
				processList.push_back(p);
				continue;
			}
			for(int i = 0; i < static_cast<int> (processList.size()); i++){
				if(arrivalTime < processList.at(i).getArrivalTime()){
					processList.insert(processList.begin() + i,p);
					break;
				}
			} 
		}
	}
	inputFS.close();

	FirstComeFirstServed(processList, numLines);
	
    //implement FCFS (non-preemptive)
    //turnaround time
    //Completedtime - Arrival time
    //waiting time
    //Turnaround time - burst duration
    //throughput
    //NEED CLARIFICATION

    //SJF

    //priority
}