//---------------------------------------------------------------------------
//
// Earthquakes' Events Analysis
// By Amirhossein Naemi
// March, 2015
// GIT: https://github.com/amirhossein-naemi/Earthquakes-Analysis-v3
// This program reads in one integer from a amir.in file and returns the
//
//---------------------------------------------------------------------------

#include "station.h"
#include "earthquake.h" // to use some functions like toupper_str

int network_code_enum(string str_net_code) {
    // Case Sensitive
    if (str_net_code == "CE")
        return 1;
    if (str_net_code == "CI")
        return 2;
    if (str_net_code == "FA")
        return 3;
    if (str_net_code == "NP")
        return 4;
    if (str_net_code == "WR")
        return 5;
    return -1;
}

int type_of_band_enum(string str_type_of_band) {

    str_type_of_band = toupper_str_C(str_type_of_band);
    toupper_str(str_type_of_band);

    if (str_type_of_band == "LONG-PERIOD")
        return 1;
    if (str_type_of_band == "SHORT-PERIOD")
        return 2;
    if (str_type_of_band == "BROADBAND")
        return 3;
    return -1;
}

string type_of_inst_string(types_of_instrument type_of_inst) {

    switch (type_of_inst) {
    case High_Gain:
        return "High Gain";
    case Low_Gain:
        return "Low Gain";
    case Accelerometer:
        return "Accelerometer";
    default:
        return "ILLEGAL";
    }
}

void station::set_network_code(network_codes network_codes_value){
    network_code = network_codes_value;
}

network_codes station::get_network_code(){
    return CE;
}




// check for rest of the errors
bool is_there_any_err(station st) {

    if (st.network_code <1 || st.network_code >5)
        return true;

    return false;
}

bool isok_network_code(string str){
    // Network code: Case sensitive: 2 characters. Must be in capital letters to
    // be valid. It can be any of the following:
    // network_code network_code;
    // string network_code;
    // char network_code;
    if (str.size() == 2)
    {
        for (int i = 0; i < 2; i++)
        {
            if (!isalpha(str[i]))
                return false;
            if (!isupper(str[i]))
                return false;
        }
        // if return true, means everything is fine
        return true;
    }
    return false;
}

bool isok_station_code(string str){
    // Station code: Case sensitive: Must be either 3 alphabetic characters in
    // capital letters, or 5 numeric characters to be valid. station_code:
    // Case Sensitive : Must be either 3 alphabetic characters in
    // capital letters, or 5 numeric characters to be valid.string ssn;
    if (str.size() == 3)
    {
        for (int i = 0; i < 3; i++)
        {
            if (!isalpha(str[i]))
                return false;
            if (!isupper(str[i]))
                return false;
        }

        // if return true, means everything is fine
        return true;
    }

    if (str.size() == 5)
    {
        for (int i = 0; i < 5; i++)
        if (!isdigit(str[i]))
        {
            // there is an error
            return false;
        }

        // if return true, means everything is fine
        return true;
    }

    // there is an error
    return false;
}


bool isok_type_of_band(string str){

    // Type of band: Case insensitive: One word. It can be any of the following
    // to be valid (the code in
    // parenthesis is for later reference):
    // string type_of_band;
    types_of_band t = (types_of_band)type_of_band_enum(str);
    if (t<1 || t>3) return false;
    return true;
}

bool isok_type_of_instrument(string str){
    // Type of instrument: Case insensitive: One word. It can be any of the
    // following to be valid (the code
    // in parenthesis is for later reference):
    // type_of_instrument type_of_instrument;
    // string type_of_instrument;
    return true;
}



bool isok_Orientation(string str){
    // Orientation: Case insensitive: a one to three characters combination.
    // Each character can be any of the following two options (alphabetic or
    // numeric, but not a combination of both):
    // N, E, or Z (one, two or three chars)
    // 1, 2, or 3 (one, two or three chars)

    toupper_str(str);
    size_t n = str.size();
    if (!isdigit(str[0]))
    {
        for (size_t i = 0; i < n; i++)
        {
            if (!(str[i] == 'N' || str[i] == 'E' || str[i] == 'Z'))
                return false; // there is an error
        }
    }
    else
    {
        for (size_t i = 0; i < n; i++)
        {
            if (!(str[i] == '1' || str[i] == '2' || str[i] == '3'))
                return false; // there is an error
        }
    }

    return true;
}

void station::set_orientation(string a) {
    try
    {
        if (!isok_Orientation(a))
            throw (51);
        else
            Orientation = a;
    }
    catch (int e)
    {
        cout << "Value of Orientation is invalid" << e << endl;
    }
}