//---------------------------------------------------------------------------
//
// Earthquakes' Events Analysis
// By Amirhossein Naemi
// March, 2015
// GIT: https://github.com/amirhossein-naemi/Earthquakes-Analysis-v3
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
#include <vector>
#include <ctime>
#include <time.h>
#include <sys/timeb.h>
#include <iomanip>
#include <sstream>

using namespace std;


//string mnth_enum2str(months mnth);

enum months {
    January, February, March, April, May, June,
    July, August, September, October, November, December
};

// Case Insensitive
enum magnitude_type {
    ML,
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

    double get_lat() { return lat; }
    void set_lat(double);
    void set_lat(string);

    double get_lon() { return lon; }
    void set_lon(double);
    void set_lon(string);

    double get_elv() { return elv; }
    void set_elv(double);
    void set_elv(string);

    double get_ms() { return ms; }
    void set_ms(double);
    void set_ms(string);

    double get_magnitude() { return magnitude; }
    void set_magnitude(double yr);
    void set_magnitude(string day);

    int get_year() { return yr; }
    void set_year(int);
    void set_year(string);

    int get_day() { return day; }
    void set_day(int);
    void set_day(string);

    int get_hour() { return hr; }
    void set_hour(int);
    void set_hour(string);

    int get_min() { return min; }
    void set_min(int);
    void set_min(string);

    int get_sec() { return sec; }
    void set_sec(int);
    void set_sec(string);

    months get_month() { return month; }
    //string get_month_str() { return mnth_enum2str(month); }
    string get_month_str();
    //months earthquake::get_month();
    void set_month(string);
    void set_month(int); // not necessary
    void set_month(months);
    
    void set_dt(string str2, ofstream & log);
    
    void set_mag(string lm, ofstream & log);

    //Proxy(My const* owner) : myOwner(owner) {}
    //operator int() const
    //{
    //    return myOwner->getInt();
    //}
    //operator char() const
    //{
    //    return myOwner->getChar();
    //}

private:
    //string id;
    //string date;
    //string time;
    //string tz;
    //string earthquake_name;
    months month;
    //magnitude_type magnitude_Type;
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
};

int str2int(const std::string& str);

months mnth_str2enum(string mnth);

void print(ofstream & , stringstream &, bool only2file = false);

inline void toupper_str(std::string& str);
string toupper_str_C(std::string str);
std::vector<std::string> &split(const std::string &s, char delim,
    std::vector<std::string> &elems);
std::vector<std::string> split(const std::string &s, char delim);
#endif