#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

//FIXME what is this top thing
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

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
    
    vector<string> cityNames;
	vector<double> temperatures;
	string tempCity;
	int tempTemp, numLines=0;

	while (!inputFS.eof()) {
		inputFS >> tempCity;
		inputFS >> tempTemp;
		if (!inputFS.fail()) {
			cityNames.push_back(tempCity);
			temperatures.push_back(tempTemp);
			++numLines; //records lines in file
		}
	}
	//closes FarhenheitTemperature.txt
	inputFS.close();

    //Read list of processes for your scheduling algorithms from a file
    //csv file with Process ID(string), arrival time(int), burst duration(int()), priority(from 1(high)-50(low))

    //implement FCFS (non-preemptive)
    //turnaround time
    //Completedtime - Arrival time
    //waiting time
    //Turnaround time - burst duration
    //throughput
    //NEED CLARIFICATION

    //SJF

    //priority
    cout << ":" << (minutes < 10 ? "0" : "") << minutes;
    cout << endl;
}

void FirstComeFirstServed(){
}

void ShortestJobFirst(int& seconds) {
	//adds one second to current time
	seconds += 1;
}

void Priority(){

}

void LoadFile(){

}