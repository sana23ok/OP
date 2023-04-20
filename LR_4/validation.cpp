#include "validation.h"
#include<iostream>
using namespace std;

bool isLeap(int year){
    return (year % 100 != 0 && year % 4 == 0) || (year % 100 == 0 && year % 400 == 0);
}
bool validateDate(int day, int month, int year){
    if(month < 1 || month > 12 || year < 1900){
        return false;
    }

    if(day < 1 || day > 31){
        return false;
    }

    if(month == 4 || month == 6 || month == 9 || month == 11){
        if(day > 30){
            return false;
        }
    }

    if(month == 2){
        if(isLeap(year) && day > 29){
            return false;
        }
        if(!isLeap(year) && day > 28){
            return false;
        }
    }
    return true;
}
void validateInput( int& d, int& m, int& y, bool& flag){
    string warning = " Invalid input...\n Try again: ";
    string input;
    bool valid = false;
    do {
        cin>>input;
        int parsed = sscanf(input.c_str(), "%d/%d/%d\n", &d, &m, &y);
        if (parsed != 3) {
            if(parsed == 2){
                valid = validateDate(d, m, 2000);
                if (!valid) cout << warning;
                else flag = true;
            }else {
                cout << warning;
            }

        }else{
            valid  = validateDate(d, m, y);
            if (!valid) cout << warning;
        }
    }while(!valid);
