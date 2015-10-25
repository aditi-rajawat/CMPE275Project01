///*
// * windroseAlgorithm10.cpp
// *
// *  Created on: Oct 17, 2015
// *      Author: aditi
// */
//
//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <sstream>
//#include <cstdlib>
//#include <cstring>
//#include <sys/time.h>
//#include <omp.h>
//#include <cmath>
//
//using namespace std;
//
//const int NUM_OF_SECTORS = 16;
//const int NUM_OF_SPEED = 5;
//const int MAX_NUM_DATA_POINTS = pow(2,27);
//
//struct MesoData
//{
//	int maxDataPoints;
//	int numDataPoints;
//	float* windDir;
//	float* windSpd;
//};
//
//typedef int outputData[NUM_OF_SECTORS][NUM_OF_SPEED];
//
//typedef int swigData[NUM_OF_SECTORS * NUM_OF_SPEED];
//
//int calcSpeedsBin(float winSpd);
//
//int calcDirectBin(float winDir);
//
//void readData(MesoData & inputData, vector<string> List);
//
//void aggData(MesoData & inputData, outputData & outData);
//
//vector<string> readFileList(string filepath);
//
//
//int main(){
//	struct timeval start, end;
//	double delta;
//
//	gettimeofday(&start, NULL);
//	cout<<"Hello World... I am processing.." << endl << endl;
//
//	string fileListpath = "InputData/2001-2009CSVs/compileList2.txt";
//	vector<string> vectorOfFilePaths = readFileList(fileListpath);
//
//	MesoData inputData = {MAX_NUM_DATA_POINTS,
//				0,
//				(float*)calloc(MAX_NUM_DATA_POINTS, sizeof(float)),
//				(float*)calloc(MAX_NUM_DATA_POINTS, sizeof(float))
//		};
//
//	outputData outData;
//
//	for(int i=0; i<NUM_OF_SECTORS; i++){
//			for(int j=0; j<NUM_OF_SPEED; j++){
//				outData[i][j] = 0;
//			}
//		}
//
//	readData(inputData, vectorOfFilePaths);
//
//	aggData(inputData, outData);
//
//	cout<<"******************** Printing final 2D array *******************************"<< endl;
//	for(int i=0; i<NUM_OF_SECTORS; i++){
//		for(int j=0; j<NUM_OF_SPEED; j++){
//			cout<< outData[i][j] << "\t";
//		}
//		cout << endl;
//	}
//
//	gettimeofday(&end, NULL);
//	delta = (end.tv_sec  - start.tv_sec) +
//		         ((end.tv_usec - start.tv_usec) / 1.e6);
//
//	cout<< endl;
//	printf("%.6lf seconds elapsed\n", delta);
//
//	free(inputData.windDir);
//	free(inputData.windSpd);
//
//}
//
//int calcSpeedsBin(float winSpd) {
//	if ( winSpd == 0) return 0;
//	else if ( winSpd > 0 and winSpd <= 5) return 1;
//	else if ( winSpd > 5 and winSpd <= 15) return 2;
//	else if ( winSpd > 15 and winSpd <= 25) return 3;
//	else if ( winSpd > 25) return 4;
//	else{
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
//	return (int)(winDir / NUM_OF_SECTORS);
//}
//
//
//void readData(MesoData & inputData, vector<string> List) {
//
//	string line, stationId="A01";
//	string path = "InputData/2001-2009CSVs/aggregateData/";
//	int count = 0;
//
//	for (int i = 0; i < List.size(); i++) {
//			ifstream inputFile(path + List[i]);
//			string rowData[6] ;
//			string token;
//			int j = 0;
//			while (getline(inputFile, line)) {
//				istringstream lineStream(line);
//				j = 0;
//				while (getline(lineStream, token, ',')) {
//					rowData[j++] = token;
//				}
//
//				if(rowData[0] == stationId){
//					inputData.windDir[count] = strtof(rowData[5].c_str(), NULL);
//					inputData.windSpd[count] = strtof(rowData[4].c_str(), NULL);
//					count++;
//				}
//
//
//				lineStream.clear();
//			}
//			inputFile.close();
//		}
//
//	inputData.numDataPoints = count;
//
//}
//
//void aggData(MesoData & inputData, outputData & outData){
//
//	omp_set_num_threads(4);
//
//		#pragma omp parallel
//		{
//			// initialising local output array for each thread
//			outputData localOutData;
//			for(int i=0; i< NUM_OF_SECTORS; i++){
//				for(int j=0; j< NUM_OF_SPEED; j++)
//					localOutData[i][j] = 0;
//			}
//
//			#pragma omp for
//			for(int i=0; i< inputData.numDataPoints;i++){
//					int d = calcDirectBin(inputData.windDir[i]);
//					int s = calcSpeedsBin(inputData.windSpd[i]);
//
//					if((d<NUM_OF_SECTORS && d>=0) && (s<NUM_OF_SPEED && s>=0))
//					localOutData[d][s]++;
//			}
//
//			for(int i=0; i< NUM_OF_SECTORS; i++){
//				for(int j=0; j< NUM_OF_SPEED; j++){
//					#pragma omp atomic
//					outData[i][j] += localOutData[i][j];
//				}
//			}
//
//		}
//
//}
//
//
//vector<string> readFileList(string filepath) {
//	vector<string> list;
//	ifstream inputfile(filepath);
//	string line;
//	while (getline(inputfile, line)) {
//		list.push_back(line);
//	}
//	inputfile.close();
//	return list;
//}
//
//
//
//
//
//
//
//
//
