//---------------------------------------------------------------------------
//
// Earthquakes' Events Analysis
// By Amirhossein Naemi
// March, 2015
// GIT: https://github.com/amirhossein-naemi/Earthquakes-Analysis-v3
// This program reads in one integer from a amir.in file and returns the
//
//---------------------------------------------------------------------------

#ifndef EARTHQUAKE_H
#define EARTHQUAKE_H

#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <ctype.h>
#include <algorithm>


using namespace std;

enum months {
    January , February, March, April, May, June,
    July, August, September, October, November, December
};
const char *mnth_int2str[] = { "January ", " February", " March", " April", " May", " June", "July"," August"," September"," October"," November"," December"};

//string mnth_enum2str(months mnth);

// Case Insensitive
enum magnitude_type {
    ML = 1,
    Ms,
    Mb,
    Mw
};

class earthquake {
public:
    
    string id;
    string date;
    string time;
    string tz;
    string earthquake_name;
    
    magnitude_type magnitude_Type;
    double lat;
    double lon;
    double elv;
    int yr;
    int day;
    int hr;
    int min;
    int sec;
    double ms;
    double magnitude;

    months get_month() { return month; }
    //string get_month_str() { return mnth_enum2str(month); }
    string get_month_str() { return mnth_int2str[month]; }
    //months earthquake::get_month();
    void set_month(string m);
    void set_month(int m);
    void set_month(months monthvalue);

private:
    //string id;
    //string date;
    //string time;
    //string tz;
    //string earthquake_name;
    months month;
    //magnitude_type magnitude_Type;
    //double lat;
    //double lon;
    //double elv;
    //int yr;
    //int day;
    //int hr;
    //int min;
    //int sec;
    //double ms;
    //double magnitude;
};

int str2int(const std::string& str);

months mnth_str2enum(string mnth);

#endif