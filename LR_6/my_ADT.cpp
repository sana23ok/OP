#include <iostream>
#include <regex>
#include "my_ADT.h"
using namespace std;

bool validateInt(const string& input) {
    regex intRegex("^[-+]?\\d+$");
    // Check if the input matches the pattern
    return regex_match(input, intRegex);
}

int choice(){
    int valid=0;
    int res=0;
    do{
        cout<<" Choose type of data:\n 1 - int\n 2 - float\n 3 - char\n 4 - string"<<endl;
        string num;
        cin>>num;
        if(validateInt(num)){
            valid =1 ;
            res = stoi(num);
        }
    }while(!valid);
    return res;
}
