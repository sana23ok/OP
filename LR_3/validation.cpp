#include "validation.h"
#include<iostream>
#include <string>
#include <sstream>
using namespace std;

bool validateInput(string input) {
    istringstream iss(input);
    float f;
    iss >> noskipws >> f;
    return iss.eof() && !iss.fail();
}

void enterData(float &num1, float &num2, float &num3) {
    string input1, input2, input3;

    do {
        cout << " Enter three numbers as strings:\n ";
        cin >> input1 >> input2 >> input3;
        fflush(stdin);
    } while (!validateInput(input1) || !validateInput(input2) || !validateInput(input3));

    num1 = stof(input1);
    num2 = stof(input2);
    num3 = stof(input3);
//    cout << "The numbers you entered as floats are: " << num1 << ", " << num2 << ", " << num3 << endl;
}