///*
// * windroseAlgorithm06.cpp
// *
// *  Created on: Oct 12, 2015
// *      Author: aditi
// */
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <cstring>
//#include <cstdlib>
//#include <sys/time.h>
//#include <omp.h>
//
//
//using namespace std;
//
//const int NUM_OF_SECTORS = 16;
//const int NUM_OF_SPEED = 5;
//const int NUM_OF_MAX_THREADS = 4;
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
//void aggData(string fileName, int tid, int wr[][NUM_OF_SPEED][NUM_OF_MAX_THREADS]);
//
//int main(){
//	struct timeval start, end;
//	double delta;
//
//	int __attribute__((aligned(64))) wr[NUM_OF_SECTORS][NUM_OF_SPEED]= {0};
//	int __attribute__((aligned(64))) local_wr[NUM_OF_SECTORS][NUM_OF_SPEED][NUM_OF_MAX_THREADS] = {0};
//
//	omp_set_num_threads(4);
//
//	gettimeofday(&start, NULL);
//
//	cout << "Hello world!! \n" << endl;
//
//	#pragma omp parallel
//	{
//
//		int tid = omp_get_thread_num();
//
//		#pragma omp for schedule(guided)
//		for(int i=0; i<50000; i++){
//			aggData("Dataset/ACME_2011.csv",tid, local_wr);
//		}
//
//		#pragma omp for collapse(2) schedule(guided)
//		for(int m=0; m< NUM_OF_SECTORS; m++){
//			for(int n=0; n< NUM_OF_SPEED; n++){
//					for(int t=0; t< NUM_OF_MAX_THREADS; t++){
//								wr[m][n] += local_wr[m][n][t];
//						}
//			}
//		}
//
//	}
//
//
//	cout<<"***** printing 2D array for windrose algorithm *****" << endl << endl;
//	#pragma omp parallel for collapse(2) ordered schedule(guided)
//	for(int m=0; m< NUM_OF_SECTORS; m++){
//		for(int n=0; n< NUM_OF_SPEED; n++){
//
//			#pragma omp ordered
//			cout << wr[m][n] << "       ";
//		}
//		//cout << endl;
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
//void aggData(string fileName, int tid, int wr[][NUM_OF_SPEED][NUM_OF_MAX_THREADS]){
//
//	string value;
//	int s,d;
//	measurements m1;
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
//		wr[d][s][tid]++;
//	}
//
//}
//
//
//
//
//
//
