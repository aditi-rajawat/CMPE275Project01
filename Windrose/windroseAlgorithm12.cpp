/*
 * windroseAlgorithm12.cpp
 *
 *  Created on: Oct 17, 2015
 *      Author: aditi
 */


#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <sys/time.h>
#include <omp.h>
#include <cmath>
#include <mm_malloc.h>

using namespace std;

const int NUM_OF_SECTORS = 16;
const int NUM_OF_SPEED = 5;
const int MAX_NUM_DATA_POINTS = pow(2,27); // 2^27 = 134217728
const int STRIP_WIDTH = 32;
const int NUM_OF_THREADS = 4;

struct MesoData
{
	int maxDataPoints;
	int numDataPoints;
	int* windDir;
	float* windSpd;
};

typedef int outputData[NUM_OF_SECTORS][NUM_OF_SPEED];

int calcSpeedsBin(float winSpd);

int calcDirectBin(int winDir);

void readData(MesoData & inputData);

void aggData(MesoData & inputData, outputData & outData);


int main(){
	struct timeval start, end;
	double delta;

	gettimeofday(&start, NULL);

	cout<<"Hello World... I am processing.." << endl << endl;

	MesoData inputData = {MAX_NUM_DATA_POINTS,
				0,
				(int*) _mm_malloc(sizeof(int)*MAX_NUM_DATA_POINTS, 64),
				(float*) _mm_malloc(sizeof(float)*MAX_NUM_DATA_POINTS, 64)
		};

	outputData outData;

	for(int i=0; i<NUM_OF_SECTORS; i++){
				for(int j=0; j<NUM_OF_SPEED; j++){
					outData[i][j] = 0;
				}
			}

	readData(inputData);

	aggData(inputData, outData);

	cout<< "******** Printing 2D Array **********" << endl;

	for(int i=0; i< NUM_OF_SECTORS; i++){
		for(int j=0; j< NUM_OF_SPEED; j++){
			cout<< outData[i][j] << "\t";
		}
	}

	gettimeofday(&end, NULL);
	delta = (end.tv_sec  - start.tv_sec) +
		         ((end.tv_usec - start.tv_usec) / 1.e6);

	cout<< endl;
	printf("%.6lf seconds elapsed\n", delta);

	free(inputData.windDir);
	free(inputData.windSpd);

}

int calcSpeedsBin(float winSpd) {
	if ( winSpd == 0) return 0;
	else if ( winSpd > 0 and winSpd <= 5) return 1;
	else if ( winSpd > 5 and winSpd <= 15) return 2;
	else if ( winSpd > 15 and winSpd <= 25) return 3;
	else if ( winSpd > 25) return 4;
	else{
		return -1;
	}
}

int calcDirectBin(int winDir) {
	// 0-360 - cut into linear line 0-359
	while(winDir<0){

		winDir = winDir + 360;
	}
	return winDir / NUM_OF_SECTORS;
}


void readData(MesoData & inputData) {
	struct timeval start, end;
	double delta;

	gettimeofday(&start, NULL);
	omp_set_num_threads(NUM_OF_THREADS);

	MesoData mesoArray[NUM_OF_THREADS];

	#pragma omp parallel
	{
		string line;
		int count = 0;

		MesoData localInData ={MAX_NUM_DATA_POINTS,
				0,
				(int*)calloc(MAX_NUM_DATA_POINTS, sizeof(int)),
				(float*)calloc(MAX_NUM_DATA_POINTS, sizeof(float))
		};

		int tid = omp_get_thread_num();

		#pragma omp for
		for(int j=0; j<50000; j++){
				ifstream inputFile("Dataset/ACME_2011.csv");
				getline(inputFile, line);	// ignoring first line of column names

				while(getline(inputFile, line)){

					string rowData[6];
					istringstream lineStream(line);
					string token;
					int i=0;
					while(getline(lineStream,token,',')){
							rowData[i++]=token;
					}

					localInData.windDir[count] = stoi(rowData[4], NULL);
					localInData.windSpd[count] = strtof(rowData[5].c_str(), NULL);

					count++;
				}
			}

		localInData.numDataPoints = count;
		mesoArray[tid] = localInData;

	}
	gettimeofday(&end, NULL);


	for(int k=0; k< NUM_OF_THREADS; k++){
		int min;
		inputData.numDataPoints += mesoArray[k].numDataPoints;

		if(k == 0)
			min=0;
		else
			min= mesoArray[k-1].numDataPoints;

		for(int n=0; n< mesoArray[k].numDataPoints; n++){
				inputData.windDir[min+n] = mesoArray[k].windDir[n];
				inputData.windSpd[min+n] = mesoArray[k].windSpd[n];
			}

		free(mesoArray[k].windDir);
		free(mesoArray[k].windSpd);
	}


	delta = (end.tv_sec  - start.tv_sec) +
			         ((end.tv_usec - start.tv_usec) / 1.e6);

	cout<< endl;
	printf("%.6lf seconds elapsed in reading the data\n", delta);
}

void aggData(MesoData & inputData, outputData & outData){

	omp_set_num_threads(NUM_OF_THREADS);

	cout<<"No. of data points = "<< inputData.numDataPoints << endl;

	#pragma omp parallel
	{
		// initialising local output array for each thread
		outputData localOutData;
		for(int i=0; i< NUM_OF_SECTORS; i++){
			for(int j=0; j< NUM_OF_SPEED; j++)
				localOutData[i][j] = 0;
		}

		#pragma omp for
		for(int k=0; k< inputData.numDataPoints; k+= STRIP_WIDTH){

			int __attribute__((aligned(64))) D[STRIP_WIDTH] ;
			int __attribute__((aligned(64))) S[STRIP_WIDTH];

			const int* winDirection = &(inputData.windDir[k]);
			const float* winSpeed = &(inputData.windSpd[k]);

			#pragma vector aligned
			for(int c=0; c<STRIP_WIDTH; c++){
				D[c] = calcDirectBin(winDirection[c]);
				S[c] = calcSpeedsBin(winSpeed[c]);
			}

			for(int c=0; c<STRIP_WIDTH; c++){
				if((D[c]<16 && D[c]>=0) && (S[c]<5 && S[c]>=0))
				localOutData[D[c]][S[c]]++;
			}
		}

		#pragma omp for
		for(int i= inputData.numDataPoints % STRIP_WIDTH; i< inputData.numDataPoints;i++){
				int d = calcDirectBin(inputData.windDir[i]);
				int s = calcSpeedsBin(inputData.windSpd[i]);

				if((d<16 && d>=0) && (s<5 && s>=0))
				localOutData[d][s]++;
		}

		for(int i=0; i< NUM_OF_SECTORS; i++){
			for(int j=0; j< NUM_OF_SPEED; j++){
				#pragma omp atomic
				outData[i][j] += localOutData[i][j];
			}
		}

	}
}
















