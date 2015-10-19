///*
// * windroseAlgorithm.cpp
// *
// *  Created on: Oct 4, 2015
// *      Author: aditi
// */
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <cstring>
//#include <cstdlib>
//#include <sys/time.h>
//
//
//
//using namespace std;
//
//const int NUM_OF_SECTORS = 16;
//const int NUM_OF_SPEED = 5;
//
//struct measurements{
//	float windSpd;
//	float windDir;
//};
//
//int calcSpeedsBin(float winSpd);
//
//int calcDirectBin(float winDir);
//
//measurements getMeas(string str);
//
//void aggData(string fileName, int wr[][NUM_OF_SPEED]);
//
//int main(){
//	struct timeval start, end;
//	double delta;
//
//	int wr[NUM_OF_SECTORS][NUM_OF_SPEED]= {0};
//
//	gettimeofday(&start, NULL);
//
//	cout << "Hello world!! \n" << endl;
//
//
//	for(int i=0; i<10; i++){
//		aggData("Dataset/ACME_2011.csv",wr);
//	}
//
//
//	cout<<"***** printing 2D array for windrose algorithm *****" << endl << endl;
//	for(int m=0; m< NUM_OF_SECTORS; m++){
//		for(int n=0; n< NUM_OF_SPEED; n++){
//			cout << wr[m][n] << "       ";
//		}
//		cout << endl;
//	}
//
//	gettimeofday(&end, NULL);
//	delta = (end.tv_sec  - start.tv_sec) +
//	         ((end.tv_usec - start.tv_usec) / 1.e6);
//
//	cout<< endl;
//	printf("%.6lf seconds elapsed\n", delta);
//}
//
//int calcSpeedsBin(float winSpd) {
//	if ( winSpd == 0) return 0;
//	else if ( winSpd > 0 and winSpd <= 5) return 1;
//	else if ( winSpd > 5 and winSpd <= 15) return 2;
//	else if ( winSpd > 15 and winSpd <= 25) return 3;
//	else if ( winSpd > 25) return 4;
//	else{
//	//	cout<< "Speed is negative.. check data file"<< endl;
//		return -1;
//	}
//}
//
//int calcDirectBin(float winDir) {
//	// 0-360 - cut into linear line 0-359
//	while(winDir<0){
//
//		winDir = winDir + 360;
//	}
//	return winDir / NUM_OF_SECTORS;
//}
//
//measurements getMeas(string str){
//	int i,j;
//	string temp1, temp2, temp3;
//	measurements meas;
//
//	i = str.find_last_of(",");
//	temp1 = str.substr(0, i);
//	temp2 = str.substr(i+1);
//
//	j = temp1.find_last_of(",");
//	temp3 = temp1.substr(j+1);
//
//	meas.windDir = strtof(temp3.c_str(), NULL);
//	meas.windSpd = strtof(temp2.c_str(), NULL);
//
//	return meas;
//}
//
//void aggData(string fileName, int wr[][NUM_OF_SPEED]){
//
//	string value;
//	int s,d;
//	measurements m1;
//
//	ifstream fileIn(fileName);
//
//	getline(fileIn, value); // To ignore the first line containing
//													// column names
//
//	while((fileIn.good()) && (!fileIn.eof())){
//		getline(fileIn, value);
//		m1 = getMeas(value);
//		s = calcSpeedsBin(m1.windSpd);
//		d = calcDirectBin(m1.windDir);
//
//		if(s== -1)
//			continue;
//
//		wr[d][s]++;
//	}
//}
//
//
//
//
//
//
