//---------------------------------------------------------------------------
//
// Earthquakes' Events Analysis
// By Amirhossein Naemi
// March, 2015
// GIT: https://github.com/amirhossein-naemi/Earthquakes-Analysis-v3
//
//---------------------------------------------------------------------------

#include "earthquake.h"
#include "station.h"
#include <ctime>
#include <time.h>
#include <sys/timeb.h>
#include <iomanip>
#include <sstream>


using namespace std;

earthquake EQ;// = {};
const int  MAXDATA = 300;
station    stations[MAXDATA];
int valid, invalid, sign;

void open_input(ifstream & ifile, string ifilename, ofstream & log) {
    // Sanity check on the file stream

    ifile.open(ifilename.c_str());
    if (!ifile.is_open()) {
        stringstream str;
        str << "Error! Cannot open input file: " << ifilename << endl;
        print(log, str);
        exit(0);
    }

    return;
}

void open_output(ofstream & o, string ofilename) {

    // Print on output file
    o.open(ofilename.c_str());
    if (!o.is_open()) {
        cout << "Error! The output file: " + ofilename + " is locked\n";

        exit(0);
    }

    return;
}


string types_of_band_str[3] = { "Longperiod", "Shortperiod", "Broadband" };
char types_of_band_char[3]        = { 'L', 'B', 'H' };
string types_of_instrument_str[3] = { "High_Gain", "Low_Gain",
"Accelerometer" };
char types_of_instrument_char[3] = { 'H', 'L', 'N' };
string network_codes_str[5]      = { "CE", "CI", "FA", "NP", "WR" };



void read_header(ifstream & in, ofstream & log) {

    string lID, ldt, lnam, lm, eID, ID, dt, nam, geo, tm, tz, magnitude_type;
    stringstream str;

    std::getline(in, lID);
    std::getline(in, ldt);
    std::getline(in, lnam);
    std::getline(in, lm);

    EQ.set_dt(ldt, log);
    EQ.set_mag(lm, log);

    // First row: Event ID
    str << eID << endl;
    print(log, str);
    str.clear();

    EQ.earthquake_name = lnam;
    EQ.id = lID;

    // Third row: Name of the earthquake (may be multiple words)
    str << lnam << endl;
    print(log, str, true);

}


void read_data(ifstream & in, ofstream & out, ofstream & log) {

    stringstream str;
    string eqnet, eqst, eqbnd, eqins, eqor;
    station   eqtmp;
    int  cnt = 0, i = 0;
    bool noerr;
    bool other_err = false;

    while (in >> eqnet) {
        cnt++;
        noerr = true;
        try
        {
            in >> eqst >> eqbnd >> eqins >> eqor;

            if (isok_network_code(eqnet))
                eqtmp.network_code = (network_codes)network_code_enum(eqnet);
            else
            {
                noerr = false;
                str << "Entry # " << setw(3) << right << cnt
                    << " ignored. Invalid network.\n";
                print(log, str);
            }

            if (isok_station_code(eqst))
                eqtmp.station_name = eqst;
            else
            {
                noerr = false;
                str << "Entry # " << setw(3) << right << cnt
                    << " ignored. Invalid station name.\n";
                print(log, str);
            }

            if (isok_type_of_band(eqbnd))
                eqtmp.type_of_band = (types_of_band)type_of_band_enum(eqbnd);
            else
            {
                noerr = false;
                str << "Entry # " << setw(3) << cnt
                    << " ignored. Invalid band type.\n";
                print(log, str);
            }

            if (isok_type_of_instrument(eqins))
                eqtmp.type_of_instrument =
                (types_of_instrument)type_of_instrument_enum(eqins);
            else
            {
                noerr = false;
                str << "Entry # " << setw(3) << cnt
                    << " ignored. Invalid instrument.\n";
                print(log, str);
            }

            if (isok_Orientation(eqor))
                eqtmp.set_orientation(eqor);
            else
            {
                noerr = false;
                str << "Entry # " << setw(3) << cnt
                    << " ignored. Invalid Orientation.\n";
                print(log, str);
            }

        }
        catch (int e)
        {
            // any other errors
            other_err = true;
            cout << "An exception occurred. Exception Nr. " << e << '\n';
        }

        if (is_there_any_err(eqtmp))
            noerr = false;

        if (other_err)
            noerr = false;

        if (noerr) {


            stations[i] = eqtmp;
            i++;
        }
    }
    invalid = cnt - i;
    valid = i;
    if (valid < 1) {
        str << "logor! input number should be equal or greater than 1\n";
        print(log, str);
        //return 2;
        exit(0);
    }

}

void process(ifstream & ifile, ofstream & log){

    stringstream str, str2;
    str.precision(3);
    str << "# " << EQ.get_day() << " " << EQ.get_month_str() << " " << EQ.get_year()
        << " " << EQ.get_hour() << ":" << EQ.get_min() << ":" << EQ.get_sec() << ":"
        << std::setprecision(3) << EQ.get_ms() << " " << EQ.tz << " "
        << EQ.magnitude_Type << " " << EQ.get_magnitude() << " "
        << EQ.earthquake_name << " [" << EQ.id << "] ("
        << EQ.get_lon() << ", " << EQ.get_lat() << ", " << EQ.get_elv() << ")" << endl;

    sign = 0;
    
    for (int i = 0; i < valid; i++) {
        string s = stations[i].get_orientation();
        char or3[5] = {};
        strcpy(or3, s.c_str());
        int n = s.size();
        for (size_t j = 0; j < n; j++) {

            str2 << EQ.id << '.'
                << network_codes_str[stations[i].network_code - 1]
                << '.' << stations[i].station_name << '.'
                << types_of_band_char[stations[i].type_of_band - 1]
                << types_of_instrument_char[stations[i].type_of_instrument - 1]
                << or3[j] 
                << endl;

            sign++;
        }
    }

    str << sign << endl;

    print(log, str, true);

    print(log, str2, true);
}

int main() {

    string       inputfilename;
    ofstream     log, out;
    ifstream     in;
    stringstream str;

    open_output(log, "amir.log");
    open_output(out, "amir.out");

    // Prompt user for input/output file
    cout << "Enter input file: ";
    cin >> inputfilename;

    // sample data for testing purposes
    // inputfilename = "amir.in";

    str << endl << "Opening file: " << inputfilename << endl;
    open_input(in, inputfilename, log);

    str << "Processing input..." << endl;
    print(log, str);

    read_header(in, log);

    str << "Header read correctly!" << endl << endl;
    print(log, str);


    read_data(in, out, log);
    process(in, out);
    print(out, str);

    str << endl << "Total invalid entries ignored: " << invalid << endl
        << "Totoal valid entries read: "   << valid << endl
        << "Total singal names produced: " << sign << endl;
    print(log, str);

    if (log.is_open())
        log.close();
    if (in.is_open())
        in.close();
    if (out.is_open())
        out.close();

    return 0;
}


