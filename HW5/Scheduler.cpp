#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <deque>
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
	}
	float turnAround = totalTurnAroundTime * 1.0 / numLines;
	float waiting = totalWaitingTime * 1.0 / numLines;
	float throughput = numLines * 1.0 / clock;
	
	stringstream s;
	s << "	--- " << "FCFS" << " ---" << endl;
	s << "Average Turnaround Time: " << turnAround << endl;
	s << "Average Waiting Time: " << waiting << endl;
	s << "Throughput: " << throughput << endl;

	return s.str();
}

string ShortestJobFirst(deque<Process> arrivalList, int numLines) {
	int turnAroundTime = 0;
	long totalTurnAroundTime = 0;
	int waitingTime = 0;
	long totalWaitingTime = 0;
	int clock = 0;
	deque<Process> ready;
	int i = 0;
	//While there are still processes or there are ready processes
	while((i < numLines) or (!ready.empty())){
		while((i < numLines) and (clock >= arrivalList.at(i).getArrivalTime())){
			if (ready.empty()){
				//First or last item added
				ready.push_back(arrivalList.at(i));
				i++;
				continue;
			} else if (ready.back().getBurstDuration() <= arrivalList.at(i).getBurstDuration()){
				ready.push_back(arrivalList.at(i));
				i++;
				continue;
			}
			for(int j = 0; j < static_cast<int> (ready.size()); j++){
				if(arrivalList.at(i).getBurstDuration() < ready.at(j).getBurstDuration()){
					ready.insert(ready.begin() + j,arrivalList.at(i));
					i++;
					break;
				}
			}
		}
		clock++;
		if((!ready.empty()) and (ready.front().decrementCounter())){
			turnAroundTime = clock - ready.front().getArrivalTime();
			waitingTime = turnAroundTime - ready.front().getBurstDuration();
			totalTurnAroundTime += turnAroundTime;
			totalWaitingTime += waitingTime;
			ready.pop_front();
			
		}
	}
	float turnAround = totalTurnAroundTime * 1.0 / numLines;
	float waiting = totalWaitingTime * 1.0 / numLines;
	float throughput = numLines * 1.0 / clock;
	
	stringstream s;
	s << "	--- " << "SJFP" << " ---" << endl;
	s << "Average Turnaround Time: " << turnAround << endl;
	s << "Average Waiting Time: " << waiting << endl;
	s << "Throughput: " << throughput << endl;

	return s.str();

}

string Priority(deque<Process> arrivalList, int numLines){
	int turnAroundTime = 0;
	long totalTurnAroundTime = 0;
	int waitingTime = 0;
	long totalWaitingTime = 0;
	int clock = 0;
	deque<Process> ready;
	int i = 0;
	//While there are still processes or there are ready processes
	while((i < numLines) or (!ready.empty())){
		while((i < numLines) and (clock >= arrivalList.at(i).getArrivalTime())){
			if (ready.empty()){
				//First or last item added
				ready.push_back(arrivalList.at(i));
				i++;
				continue;
			} else if (ready.back().getPriority() <= arrivalList.at(i).getPriority()){
				ready.push_back(arrivalList.at(i));
				i++;
				continue;
			}
			for(int j = 0; j < static_cast<int> (ready.size()); j++){
				if(arrivalList.at(i).getPriority() < ready.at(j).getPriority()){
					ready.insert(ready.begin() + j,arrivalList.at(i));
					i++;
					break;
				}
			}
		}
		clock++;
		if((!ready.empty()) and ready.front().decrementCounter()){
			turnAroundTime = clock - ready.front().getArrivalTime();
			waitingTime = turnAroundTime - ready.front().getBurstDuration();
			totalTurnAroundTime += turnAroundTime;
			totalWaitingTime += waitingTime;
			ready.pop_front();
			
		}
	}
	float turnAround = totalTurnAroundTime * 1.0 / numLines;
	float waiting = totalWaitingTime * 1.0 / numLines;
	float throughput = numLines * 1.0 / clock;
	
	stringstream s;
	s << "	--- " << "Priority" << " ---" << endl;
	s << "Average Turnaround Time: " << turnAround << endl;
	s << "Average Waiting Time: " << waiting << endl;
	s << "Throughput: " << throughput << endl;

	return s.str();


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

int main(int argc, char* argv[]) {
	//TODO throughput value is incorrect
	if (argc < 2){
		return 1;
	}
	string inputFile = argv[1];	
    fstream inputFS (inputFile);

    //Check if the file is open or not
	if (!inputFS.is_open()) {
		std::cout << "Could not open file" << endl;
		return 1;
	}

	int numLines=0;
	deque<Process> processList;
	string currLine;
	while (getline (inputFS, currLine, '\n')) {
		++numLines; //records lines in file

		if (!inputFS.fail()) {
			Process p = createProcess(currLine);
			//std::cout << p.getPID() << " " << p.getArrivalTime() << " " << p.getBurstDuration() << " " << p.getPriority() << endl;
			if (processList.empty()){
				//First item added
				processList.push_back(p);
				continue;
			}
			bool atEnd = true;
			for(int i = 0; i < static_cast<int> (processList.size()); i++){
				if(p.getArrivalTime() < processList.at(i).getArrivalTime()){
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
	std::cout << ShortestJobFirst(processList, numLines);
	std::cout << Priority(processList, numLines);
}