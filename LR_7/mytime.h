#ifndef MYTIME_H
#define MYTIME_H
#include<iostream>
#include<sstream>
#include<iomanip>
using namespace std;

class MyTime {
private:
//    string format_24;
    int h, m, s;

public:

    MyTime(){}
    MyTime(int hh, int mm, int ss){
        h=hh;
        m=mm;
        s=ss;
    }

    bool isInFirstPartOfDay() const {
        return (h >= 0 && h < 12);
    }

    string get_time() {
        stringstream ss;
        ss << setfill('0') << setw(2) << h << ":" << setw(2) << m << ":" << setw(2) << s;
        return ss.str();
    }

};

bool checkTimeFormat(const string& time);
bool message(string input);

#endif // MYTIME_H
