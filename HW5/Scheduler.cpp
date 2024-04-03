#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

//FIXME what is this top thing
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <deque>
#include <vector>
#include <sstream> 
#include "Process.h"

using namespace std;

string FirstComeFirstServed(deque<Process> arrivalList, int numLines){
	int clock = 0;
	int turnAroundTime = 0;
	long totalTurnAroundTime = 0;
	int waitingTime = 0;
	long totalWaitingTime = 0;
	for (int i = 0; i < numLines; i++){
		Process currProcess = arrivalList.at(i);
		//Case that no-proces has arrived
		if (clock < currProcess.getArrivalTime()){
			clock = currProcess.getArrivalTime();
		}
		//Same process for every other case
		clock += currProcess.getBurstDuration();
		turnAroundTime = clock - currProcess.getArrivalTime();
		waitingTime = turnAroundTime - currProcess.getBurstDuration();
		totalTurnAroundTime += turnAroundTime;
		totalWaitingTime += waitingTime;
		std::cout << "yo " << currProcess.getArrivalTime() << endl;
	}
	float turnAround = totalTurnAroundTime * 1.0 / numLines;
	float waiting = totalWaitingTime * 1.0 / numLines;
	float throughput = 1.0 / turnAroundTime;
	
	stringstream s;
	s << "	--- " << "First Come First Served" << " ---" << endl;
	s << "Average Turnaround Time: " << turnAround << endl;
	s << "Average Waiting Time: " << waiting << endl;
	s << "Throughput: " << throughput << endl;

	return s.str();
}

void ShortestJobFirst(deque<Process> arrivalList, int numLines) {
	int clock = 0;
	numLines++;
	while(true){
		for(int i = 0; clock == arrivalList.at(i).getArrivalTime(); i++){break;}
		break;


	}

}

void Priority(){

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
	//TODO THIS CANNOT BE HARDCODED
    //string inputFile = "CS370-HW5-Input.csv";
	string inputFile = "AtestFile.csv";
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
	deque<Process> processList;
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
			bool atEnd = true;
			for(int i = 0; i < static_cast<int> (processList.size()); i++){
				if(arrivalTime > processList.at(i).getArrivalTime()){
					processList.insert(processList.begin() + i,p);
					atEnd = false;
					break;
				}
			}
			if(atEnd){
				processList.push_back(p);
			}
		}
	}
	inputFS.close();

	std::cout << FirstComeFirstServed(processList, numLines);
	//std::cout << ShortestJobFirst(processList, numLines);
	//std::cout << Priority(processList, numLines);
	
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