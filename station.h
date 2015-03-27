//---------------------------------------------------------------------------
//
// Earthquakes' Events Analysis
// By Amirhossein Naemi
// March, 2015
// GIT: https://github.com/amirhossein-naemi/Earthquakes-Analysis-v3
//
//---------------------------------------------------------------------------

#ifndef STATION_H
#define STATION_H

#include "earthquake.h"
#include <string>

// Long_period  (L)
// Short_period (B)
// Broadband    (H)
// Case Insensitive
enum types_of_band {
    Long_period  = 1,
    Short_period = 2,
    Broadband    = 3
};

// Case Insensitive
enum types_of_instrument {
    High_Gain = 1,
    Low_Gain,
    Accelerometer
};


// Case Sensitive
enum network_codes {
    CE = 1,
    CI,
    FA,
    N,
    NP,
    WR
};

// not needed
enum Orientation {
    NN, E, Z
};

// Following a valid header, the input file has an indefinite number of entries
// , one per row, but no more than 300 (this limit is important, as you are
// supposed to crete an array to store the input entries). Each entry in the
// table is composed of the following:

class station {
public:
    void set_network_code(network_codes network_codes_value);
    network_codes get_network_code();
    network_codes       network_code;
    string              station_name;
    types_of_band       type_of_band;
    types_of_instrument type_of_instrument;
    //string              Orientation;
    string get_orientation() { return Orientation; }
    void set_orientation(string);

private:
    //network_codes       network_code;
    //string              station_name;
    //types_of_band       type_of_band;
    //types_of_instrument type_of_instrument;
    string              Orientation;
};

int network_code_enum(string str_net_code);
int type_of_instrument_enum(string str_type_of_inst);
int type_of_band_enum(string str_type_of_band);
string type_of_inst_string(types_of_instrument type_of_inst);

bool isok_Orientation(string);// temp remove
bool isok_type_of_instrument(string);
bool isok_type_of_band(string);
bool isok_station_code(string);
bool isok_network_code(string);
bool is_there_any_err(station);

#endif