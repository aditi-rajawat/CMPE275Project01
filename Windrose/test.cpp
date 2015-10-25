///*
// * test.cpp
// *
// *  Created on: Oct 4, 2015
// *      Author: aditi
// */
//#include <iostream>
//#include <fstream>
//#include <ctime>
//#include <iomanip>
//#include <sstream>
//#include <string>
//#include <time.h>
//
//using namespace std;
//
//bool isBetween(string start, string end);
//
//int main()
//{
//
//	string line, token, value, stationId;
//	int i=1,startYr, endYr, startMon, endMon, startDt, endDt, hours, mins, secs;
//	string rowData[5];
//	time_t rawtime;
//	struct tm * startTime, * endTime;
//	char buffer [80];
//	const char* TIME_ZONE = "PDT";
//
//	time (&rawtime);
//	startTime = localtime (&rawtime);
//	endTime = localtime (&rawtime);
//
//	cout<< "****** Hello World!! ******" << endl;
//	cout<<"Enter following inputs to get winrose plot"<< endl << endl;
//
//	cout<<"Station Id = ";
//	cin>> stationId;
//
//	cout<< "\n Start Year = ";
//	cin>> startYr;
//
//	cout<< "\n End Year = ";
//	cin>> endYr;
//
//	cout<<"\n Start Month = ";
//	cin>> startMon;
//
//	cout<<"\n End Month = ";
//	cin>> endMon;
//
//	cout<<"\n Start Date = ";
//	cin>> startDt;
//
//	cout<<"\n End Date = ";
//	cin>> endDt;
//
//	cout<<"\n Time stamp hour =  ";
//	cin>> hours;
//
//	cout<<"\n Time stamp mins =  ";
//	cin>> mins;
//
//	cout<<"\n Time stamp secs =  ";
//	cin>> secs;
//
////	startTime->tm_year = startYr;
////	startTime->tm_mon = startMon;
////	startTime->tm_mday = startDt;
////	startTime->tm_hour = hours;
////	startTime->tm_min = mins;
////	startTime->tm_sec = secs;
////	startTime->tm_zone = TIME_ZONE;
////
////	strftime (buffer,80,"\nStart time is %a %b %d %T %Z %Y",startTime);
////
////	puts(buffer);
////
////	endTime->tm_year = endYr;
////	endTime->tm_mon = endMon;
////	endTime->tm_mday = endDt;
////	endTime->tm_hour = hours;
////	endTime->tm_min = mins;
////	endTime->tm_sec = secs;
////	endTime->tm_zone = TIME_ZONE;
//
//
//
//	//strftime (buffer,80,"\nEnd time is %a %b %d %T %Z %Y",endTime);
//
//	//puts(buffer);
//
//
////	ifstream inputFile("Dataset/07-01_mesonet-20010701_2200.csv");
////
////	getline(inputFile, line);
////	istringstream lineStream(line);
////
////	while(getline(lineStream,token,',')){
////
////		switch(i){
////		case 1: // station Id
////			if (token.compare(stationId) == 0)
////				i++;
////			else
////				i = -1;
////			break;
////
////		case 2:
////			i++;
////			break;
////
////		case 3:
////			istringstream str(token);
////			while(getline(str,value,' ')){
////				if(value.find(start))
////			}
////
////		}
////
////		cout << "Speed = "<< strtof(rowData[3].c_str(), NULL) << endl;
////		cout <<"Direction = "<< strtof(rowData[4].c_str(), NULL) << endl;
////
////		if(i==5)
////			i=1;
////		else
////			i++;
////	}
//
//}
//
//
//bool isBetween(string start, string end, string currentTime){
//// format is Sun Jul 01 15:00:00 PDT 2001
//
//	string token1, token2;
//	istringstream str1(start), str2(end);
//	string monArr[] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
//	int i=0;
//
//	while((getline(str1,token1,',')) && (getline(str2,token2,','))){
//
//		switch(i){
//
//		case 0:
//			continue;
//		case 1:
//			int s = monArr
//		}
//	}
//
//}
//
//
//
