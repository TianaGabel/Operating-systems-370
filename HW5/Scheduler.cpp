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
#include "Process.h"

using namespace std;

int main() {
	char userNum = '0';
	int secShift = 0;
	int minShift = 0;
	int hourShift = 0;
	int sec_prev = 0;

    string inputFile;
    ifstream inputFS (inputFile);

    //Check if the file is open or not
	if (!inputFS.is_open()) {
		cout << "Could not open file" << endl;
		return 1;
	}

    //We will have to ask about what file types are allowed
    //We need a fifo/queue for FCFS
    //We need a heap for SJF
	string PID;
	int arrivalTime;
	int burstDuration;
	int priority;

	int numLines=0;
	vector<Process> processList; 

	//Adds all elements to queue
	while (!inputFS.eof()) {
		inputFS >> PID;
		inputFS >> arrivalTime;
		inputFS >> burstDuration;
		inputFS >> priority;
		++numLines; //records lines in file

		if (!inputFS.fail()) {
			Process p = Process(PID, arrivalTime, burstDuration, priority);
			if (processList.empty()){
				//First item added
				processList.push_back(p);
				continue;
			}
			for(int i = 0; i < processList.size(); i++){
				if(arrivalTime < processList.at(i).getArrivalTime()){
					processList.insert(processList.begin() + i,p);
				}
			} 
		}
	}
	inputFS.close();

	FirstComeFirstServed(processList);
	
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

void FirstComeFirstServed(vector<Process> arrivalList){
	for (auto process : arrivalList){
		cout << process.getArrivalTime() << "  ";
		cout << endl;
	}

}

void ShortestJobFirst(int& seconds) {
	//adds one second to current time
	seconds += 1;
}

void Priority(){

}

void PrintFormatting(string algo, float turnAroundTime, float waitingTime, float throughput ){
	cout << "	--- " << algo << " ---" << endl;
	cout << "Average Turnaround Time: " << turnAroundTime << endl;
	cout << "Average Waiting Time: " << waitingTime << endl;
	cout << "Throughput: " << throughput << endl;

}