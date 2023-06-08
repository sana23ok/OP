#include "mytime.h"
#include <iostream>
#include <sstream>
#include <regex>
using namespace std;

bool checkTimeFormat(const string& time) {
    regex timeRegex("^([01]?[0-9]|2[0-3]):([0-5][0-9]):([0-5][0-9])$");
    if (!regex_match(time, timeRegex))
        return false;

    istringstream ss(time);
    char delimiter;
    int hours, minutes, seconds;

    ss >> hours >> delimiter >> minutes >> delimiter >> seconds;

    return (hours < 24 && minutes < 60 && seconds < 60);
}

bool message(string input){
    if (checkTimeFormat(input)) {
        return true;
    } else {
        return false;
    }
}

