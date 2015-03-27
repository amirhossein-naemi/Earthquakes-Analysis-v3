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


// **************************** month *****************************
const char *months2str[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
string earthquake::get_month_str() { return months2str[month]; }


//string mnth_enum2str(months mnth) {// not nec
//
//    switch (mnth) {
//    case January:
//        return "January";
//    case February:
//        return "February";
//    case March:
//        return "March";
//    case April:
//        return "April";
//    case May:
//        return "May";
//    case June:
//        return "June";
//    case July:
//        return "July";
//    case August:
//        return "August";
//    case September:
//        return "September";
//    case October:
//        return "October";
//    case November:
//        return "November";
//    case December:
//        return "December";
//    default:
//        return "ILLEGAL";
//    }
//}

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

// **************************** END *****************************

// **************************** day *****************************
void earthquake::set_day(int d) {
    try
    {
            if (d < 1 || d > 31)
                throw (20);
    else
        day = d;
    }
    catch (int e)
    {
        cout << "Value of dayy is invalid" << endl;
    }
}
void earthquake::set_day(string a){
    int b = str2int(a);
    set_day(b);
}

void earthquake::set_year(int y) {
    try
    {
        if (y < 1800 || y > 2100)
            throw (21);
        else
        yr = y;
    }
    catch (int e)
    {
        //cout << "An exception occurred. Exception Nr. " << e << '\n';
        cout << "Value of year is invalid" << e << endl;
    }
}
void earthquake::set_year(string a){
    try
    {
        int b = str2int(a);
        set_year(b);
    }
    catch (int e)
    {
        set_year(-1);
    }
}

void earthquake::set_hour(int a) {
    try
    {
        if (a < 0 || a > 24)
            throw (22);
        else
            hr = a;
    }
    catch (int e)
    {
        cout << "Value of hour is invalid" << e << endl;
    }
}
void earthquake::set_hour(string a){
    try
    {
        int b = str2int(a);
        set_hour(b);
    }
    catch (int e)
    {
        set_hour(-1);
    }
}


void earthquake::set_min(int a) {
    try
    {
        if (a < 0 || a > 59)
            throw (23);
        else
            min = a;
    }
    catch (int e)
    {
        cout << "Value of minute is invalid" << e << endl;
    }
}
void earthquake::set_min(string a){
    try
    {
        int b = str2int(a);
        set_min(b);
    }
    catch (int e)
    {
        set_min(-1);
    }
}


void earthquake::set_sec(int a) {
    try
    {
        if (a < 0 || a > 59)
            throw (22);
        else
            sec = a;
    }
    catch (int e)
    {
        cout << "Value of second is invalid" << e << endl;
    }
}
void earthquake::set_sec(string a){
    try
    {
        int b = str2int(a);
        set_sec(b);
    }
    catch (int e)
    {
        set_sec(-1);
    }
}

//bool isok_date() {
//
//    if (EQ.yr > 2100 || EQ.yr<1900)
//        return false;
//
//    if (EQ.day>31 || EQ.day < 1)
//        return false;
//
//    return true;
//
//}

bool isok_time(string str) {
    string delim = "/";
    return true;
}

bool isok_timezone(string str) {
    toupper_str(str);
    if (str == "PST" || str == "CST" || str == "EST" || str == "MST")
        return true;
    return false;
}

















// **************************** dt *****************************

void earthquake::set_dt(string str2, ofstream & log)
{

    stringstream stro;
    string dt, tm, tz;
    string year, mnth, day, hour, min, sec, ms;

    try {

        char str[50];
        strncpy(str, str2.c_str(), sizeof(str));
        str[sizeof(str)-1] = 0;

        replace(str, str + strlen(str), '/', ' ');
        replace(str, str + strlen(str), ':', ' ');

        std::vector<std::string> aln = split(str2, ' ');
        std::vector<std::string> adt = split(aln[0], '/');
        std::vector<std::string> atm = split(aln[1], ':');
        std::vector<std::string> asc = split(atm[2], '.');

        bool dateisOK = true;
        bool timeisOK = true;

        size_t n1 = adt.size();
        for (size_t i = 0; i < n1; i++)
        {
            size_t n2 = adt[i].size();
            for (size_t ii = 0; ii < n2; ii++)
            {
                if (!isdigit(adt[i][ii]))
                    // there is an error
                    dateisOK = false;
            }
        }

        n1 = atm.size() - 1;
        for (size_t i = 0; i < n1; i++)
        {
            size_t n2 = atm[i].size();
            for (size_t ii = 0; ii < n2; ii++)
            {
                if (!isdigit(atm[i][ii]))
                    // there is an error
                    timeisOK = false;
            }
        }

        if (dateisOK)
        {
            day = adt[1];
            year = adt[2];
            hour = atm[0];

            //EQ.month = mnth_str2enum(adt[0]);
            set_month(adt[0]);
            //EQ.day = str2int(day);
            set_day(day);
            //EQ.yr = str2int(year);
            set_year(year);
        }

        if (timeisOK)
        {
            min = atm[1];
            sec = asc[0];
            ms = asc[1];
            tz = aln[2];

            hr = str2int(hour);
            min = str2int(min);
            sec = str2int(sec);
            ms = str2int(ms);
            tz = tz;
        }


        //if (!isok_date() || !dateisOK)
        //{
        //    stro << "Error! date is invalid" << endl;
        //    print(log, stro);
        //    exit(0);
        //}

        //if (!isok_time(aln[1]) || !isok_timezone(tz) || !timeisOK)
        //{
        //    stro << "Error! time is invalid" << endl;
        //    print(log, stro);
        //    exit(0);
        //}

    }
    catch (int n) {
        stro << "Error! date/time is invalid" << endl;
        print(log, stro);
        exit(0);
    }
}
















int type_of_instrument_enum(string str_type_of_inst) {
    toupper_str(str_type_of_inst);
    //Case insensitive
    if (str_type_of_inst == "LOW-GAIN")
        return 1;
    if (str_type_of_inst == "HIGH-GAIN")
        return 2;
    if (str_type_of_inst == "ACCELEROMETER")
        return 2;
    return -1;
}



// **************************** general functions (put them on a seperate file?) *******************




void toupper_str(std::string& str) {

    for (size_t i = 0; i < str.size(); ++i)
        str[i] = toupper(str[i]);

}

string toupper_str_C(std::string str) {

    toupper_str(str);

    return str;
}

std::vector<std::string> &split(const std::string &s, char delim,
    std::vector<std::string> &elems) {

    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }

    return elems;
}

std::vector<std::string> split(const std::string &s, char delim) {

    std::vector<std::string> elems;
    split(s, delim, elems);

    return elems;
}

void print(ofstream & o, stringstream & txt, bool only2file) {

    std::cout.precision(3);
    o.precision(3);

    if (!only2file) cout << txt.str();

    o << txt.str();

    txt.str(std::string());
    txt.clear();
}

