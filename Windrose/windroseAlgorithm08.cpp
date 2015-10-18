///*
// * windroseAlgorithm08.cpp
// *
// *  Created on: Oct 12, 2015
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
//
//using namespace std;
//
//
//int NUM_OF_SECTORS = 16;
//int SPEED_BUCKETS=5;
//int const NUM_OF_MAX_THREADS = 4;
//
//struct MesoData
//{
//	float windDir;
//	float windSpd;
//};
//
//int calcSpeedsBin(float winSpd);
//
//int calcDirectBin(float winDir);
//
//vector<MesoData> readData();
//
//void aggData(vector<MesoData> data);
//
//
//int main(){
//	struct timeval start, end;
//	double delta;
//	gettimeofday(&start, NULL);
//
//	cout<<"Hello World... I am processing.." << endl << endl;
//
//	omp_set_num_threads(NUM_OF_MAX_THREADS);
//
//	vector<MesoData> inputData= readData();
//	aggData(inputData);
//
//	gettimeofday(&end, NULL);
//	delta = (end.tv_sec  - start.tv_sec) +
//		         ((end.tv_usec - start.tv_usec) / 1.e6);
//
//	cout<< endl;
//	printf("%.6lf seconds elapsed\n", delta);
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
//
//
//
//vector<MesoData> readData() {
//
//	//MesoData* ptr = (MesoData*)malloc(sizeof(vector<MesoData>));
//	vector<MesoData> inData;
//	string line;
//	string temp1, temp2, temp3;
//	int i,j;
//
//	for(int k=0; k<50000; k++){
//		ifstream  inputfile("Dataset/ACME_2011.csv");
//		getline(inputfile,line);
//
//
//		while((inputfile.good()) && (!inputfile.eof()))
//		{
//
//			getline(inputfile,line);
//
//			i = line.find_last_of(",");
//			temp1 = line.substr(0, i);
//			temp2 = line.substr(i+1);
//
//			j = temp1.find_last_of(",");
//			temp3 = temp1.substr(j+1);
//
//		   MesoData mesoData ={
//			strtof(temp3.c_str(), NULL),
//			strtof(temp2.c_str(), NULL)
//		   };
//		   inData.push_back(mesoData);
//
//		}
//	}
//    return inData;
//}
//
//void aggData(vector<MesoData> data){
//
//	int wr[NUM_OF_SECTORS][SPEED_BUCKETS]={0};
//	//vector<MesoData>::iterator it = data.begin();
//
//	cout<<"Size of vector: "<< data.size()<< endl << endl;
//
//	#pragma omp parallel for
//	for(int index=0; index< data.size(); index++)
//	{
//		MesoData m = data[index];
//		int s = calcSpeedsBin(m.windSpd);
//		int d = calcDirectBin(m.windDir);
//
//		if(s== -1)
//			continue;
//
//		#pragma omp atomic
//		wr[d][s]++;
//
//	}
//
//	cout<<"         Final 2DArray for plotting"<<endl;
//	cout<<"=============================================="<<endl;
//	cout<<endl;
//
//	//printing the 2D Array
//	//#pragma omp parallel for ordered
//	for (int i = 0; i < NUM_OF_SECTORS; i++){
//		for (int j = 0; j < SPEED_BUCKETS; j++){
//				cout << wr[i][j] <<"\t";
//		}
//		cout <<endl;
//	}
//
//	//free((void*)data);
//}
//
//
//
//
//
//
//
//
