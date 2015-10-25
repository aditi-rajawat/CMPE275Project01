///*
// * test2.cpp
// *
// *  Created on: Oct 22, 2015
// *      Author: aditi
// */
//#include <stdio.h>      /* puts */
//#include <time.h>       /* time_t, struct tm, time, localtime, strftime */
//
//int main ()
//{
//
//  time_t rawtime;
//  struct tm * timeinfo;
//  char buffer [80];
// // char timeZone[] = {'P','D','T'};
//  time (&rawtime);
//  timeinfo = localtime (&rawtime);
//
//  timeinfo->tm_year = 2001;
//  timeinfo->tm_mon = 02;
//  timeinfo->tm_mday = 23;
//  timeinfo->tm_hour =15;
//  timeinfo->tm_zone = "PDT";
//
//  strftime (buffer,80,"Now it's %a %b %d %T %Z %Y",timeinfo);
//  puts (buffer);
//
//  return 0;
//}
//
//
//
