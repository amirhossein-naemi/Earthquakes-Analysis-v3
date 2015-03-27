//---------------------------------------------------------------------------
//
// Earthquakes' Events Analysis
// By Amirhossein Naemi
// March, 2015
// GIT: https://github.com/amirhossein-naemi/Earthquakes-Analysis-v3
// This program reads in one integer from a amir.in file and returns the
//
//---------------------------------------------------------------------------

#include "earthquake.h"

int str2int(const std::string& str)
{
    int result = 0;

    std::string::const_iterator i = str.begin();

    if (i == str.end())
        return false;

    bool negative = false;

    if (*i == '-')
    {
        negative = true;
        ++i;

        if (i == str.end())
            return false;
    }

    result = 0;

    for (; i != str.end(); ++i)
    {
        if (*i < '0' || *i > '9')
            return false;

        result *= 10;
        result += *i - '0';
    }

    if (negative)
        result = -result;

    return result;
}

string mnth_enum2str(months mnth) {

    switch (mnth) {
    case January:
        return "January";
    case February:
        return "February";
    case March:
        return "March";
    case April:
        return "April";
    case May:
        return "May";
    case June:
        return "June";
    case July:
        return "July";
    case August:
        return "August";
    case September:
        return "September";
    case October:
        return "October";
    case November:
        return "November";
    case December:
        return "December";
    default:
        return "ILLEGAL";
    }
}

months mnth_str2enum(string mnth) {

    int imnth = str2int(mnth);

    switch (imnth) {
    case 1:
        return January;
    case 2:
        return February;
    case 3:
        return March;
    case 4:
        return April;
    case 5:
        return May;
    case 6:
        return June;
    case 7:
        return July;
    case 8:
        return August;
    case 9:
        return September;
    case 10:
        return  October;
    case 11:
        return November;
    case 12:
        return December;
    //default:
    //    return -1;
    }
}

void earthquake::set_month(string m) {
    try
    {
        month = mnth_str2enum(m);
    }
    catch (int e)
    {
        cout << "Value of month is invalid" << endl;
    }
}
void earthquake::set_month(int m2) {

    if (m2 < 1 || m2 > 12)
        cout << "Value of month is invalid" << endl;
    else
    {
        months m = static_cast<months>(m2);
        month = m;
    }

}
void earthquake::set_month(months monthvalue) {
    try
    {
        month = monthvalue;
    }
        
    catch (int e)
    {
        cout << "Value of month is invalid" << endl;
    }
}
//months earthquake::get_month(){
//    return January;
//}