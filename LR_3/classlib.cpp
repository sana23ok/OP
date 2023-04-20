<<<<<<< HEAD
#include"classlib.h"
#include"validation.h"
#include<cstdio>
#include<conio.h>
#include<iostream>
#include <string>
#include<regex>
using namespace std;

class Point;
class Tetraedr;

void Point::getPoint(float& xx, float& yy, float& zz) {
    xx = x; yy = y; zz = z;
}

void Point::printPoint() {
    cout << "\t(" << x << ", " << y << ", " << z << ")" << endl;
}

float Tetraedr::volume() {
    float x[4], y[4], z[4];
    float vectorX[3], vectorY[3], vectorZ[3];
    for (int i = 0; i < 4; i++) {
        obj[i].getPoint(x[i], y[i], z[i]);
    }
    int j = 1;
    for (int i = 0; i < 3; i++) {
        /* vectorX[0] vectorY[0] vectorZ[0]
         * vectorX[1] vectorY[1] vectorZ[1]
         * vectorX[2] vectorY[2] vectorZ[2]*/
        vectorX[i] = x[j] - x[0];
        vectorY[i] = y[j] - y[0];
        vectorZ[i] = z[j] - z[0];
        j++;
    }
    float V = (vectorX[0] * vectorY[1] * vectorZ[2]) + (vectorY[0] * vectorZ[1] * vectorX[2])
              + (vectorZ[0] * vectorX[1] * vectorY[2]) - (vectorZ[0] * vectorY[1] * vectorX[2])
              - (vectorX[0] * vectorZ[1] * vectorY[2]) - (vectorY[0] * vectorX[1] * vectorZ[2]);
    return V;
}

int answ() {
    regex regex("[12]");
    string input;
    bool invalid;
    cout << " Enter '1' to generate points, '2' to fill them manually:";
    int res;
    do {
        cin >> input;
        fflush(stdin);
        if(regex_match(input, regex)) {
            invalid = false;
            res = stoi(input);
        }
        else {
            cout << " Invalid input. Try again...\n Enter a number:";
            invalid = true;
        }
    } while(invalid);
    return res;
}

void generate(Point* A) {
    for (int i = 0; i < 4; i++) {
        A[i] = Point(rand() % 101-50, rand() % 101-50, rand() % 101-50);
    }
}

void fill(Point* A) {
    float x, y, z;
    cout << " Enter x, y and z as a string\n";
    for (int i = 0; i < 4; i++) {
        cout << " Point N[" << i + 1 << "]" << endl;
        enterData(x, y, z);
        A[i] = Point(x, y, z);
    }
}

void task(Point* arr, Tetraedr* objArr, float &max, int &ind) {
    char ch;
    bool flag;
    int i=0;
    do {
        generate(arr);
        objArr[i]= Tetraedr(arr);
        float V = objArr[i].getV();
        if (V <= 0) {
            i--;
            flag = false;
        }
        else {
            cout << " Coordinates of vertex N[" << i + 1 << "]:" << endl;
            for (int t = 0; t < 4; t++){
                arr[t].printPoint();
            }
            cout << " Volume: " << V << endl;
            if(i==0){
                max = V;
                ind = i;
            }else if(max<V && i>0){
                max = V;
                ind = i;
            }
            flag = true;
            cout << "\tPress 'ENTER' to continue, another key to stop..." << endl;
            ch = _getch();
        }
        i++;
        if(i==30){cout<<"You can generate only 30 object !!!"<<endl; break; }
    } while (ch == 13 || !flag );
}

void task(Point* arr, Tetraedr* objArr, bool &flag, float &max, int &ind) {
    int i=0;
    do{
        fill(arr);
        cout << " Coordinates of vertex N[" << i + 1 << "]:" << endl;
        for (int t = 0; t < 4; t++) {
            arr[t].printPoint();
        }

        objArr[i]= Tetraedr(arr);
        float V = objArr[i].getV();
        if (V == 0) {
            cout << " Object doesn't exist...." << endl;
        }
        else {
            cout << " Volume: " << V << endl;
            if(V>0 && i==0){
                max = V;
                ind = i;
            }else if(max<V && i>0){
                max = V;
                ind = i;
            }
            flag = true;
        }
                i++;
                cout << "\tPress 'ENTER' to continue, another key to stop..." << endl;
        if(i==30){ cout<<"You can enter only 30 object !!!"<<endl; break; }
    } while (_getch() == 13);
}

void displayRes(float V, int i, bool flag){
    if(flag){
        cout<< " Object with max volume is N["<<i+1<<"]"<<endl<<" Volume = "<< V <<endl;
    }else{
        cout<<"--- All of the objects from list don't have volume!!! ---"<<endl;
    }
}
=======
#include"classlib.h"
#include"validation.h"
#include<cstdio>
#include<conio.h>
#include<iostream>
#include <string>
#include<regex>
using namespace std;

class Point;
class Tetraedr;

void Point::getPoint(float& xx, float& yy, float& zz) {
    xx = x; yy = y; zz = z;
}

void Point::printPoint() {
    cout << "\t(" << x << ", " << y << ", " << z << ")" << endl;
}

float Tetraedr::volume() {
    float x[4], y[4], z[4];
    float vectorX[3], vectorY[3], vectorZ[3];
    for (int i = 0; i < 4; i++) {
        obj[i].getPoint(x[i], y[i], z[i]);
    }
    int j = 1;
    for (int i = 0; i < 3; i++) {
        /* vectorX[0] vectorY[0] vectorZ[0]
         * vectorX[1] vectorY[1] vectorZ[1]
         * vectorX[2] vectorY[2] vectorZ[2]*/
        vectorX[i] = x[j] - x[0];
        vectorY[i] = y[j] - y[0];
        vectorZ[i] = z[j] - z[0];
        j++;
    }
    float V = (vectorX[0] * vectorY[1] * vectorZ[2]) + (vectorY[0] * vectorZ[1] * vectorX[2])
              + (vectorZ[0] * vectorX[1] * vectorY[2]) - (vectorZ[0] * vectorY[1] * vectorX[2])
              - (vectorX[0] * vectorZ[1] * vectorY[2]) - (vectorY[0] * vectorX[1] * vectorZ[2]);
    return V;
}

int answ() {
    regex regex("[12]");
    string input;
    bool invalid;
    cout << " Enter '1' to generate points, '2' to fill them manually:";
    int res;
    do {
        cin >> input;
        fflush(stdin);
        if(regex_match(input, regex)) {
            invalid = false;
            res = stoi(input);
        }
        else {
            cout << " Invalid input. Try again...\n Enter a number:";
            invalid = true;
        }
    } while(invalid);
    return res;
}

void generate(Point* A) {
    for (int i = 0; i < 4; i++) {
        A[i] = Point(rand() % 101-50, rand() % 101-50, rand() % 101-50);
    }
}

void fill(Point* A) {
    float x, y, z;
    cout << " Enter x, y and z as a string\n";
    for (int i = 0; i < 4; i++) {
        cout << " Point N[" << i + 1 << "]" << endl;
        enterData(x, y, z);
        A[i] = Point(x, y, z);
    }
}

void task(Point* arr, Tetraedr* objArr, float &max, int &ind) {
    char ch;
    bool flag;
    int i=0;
    do {
        generate(arr);
        objArr[i]= Tetraedr(arr);
        float V = objArr[i].getV();
        if (V <= 0) {
            i--;
            flag = false;
        }
        else {
            cout << " Coordinates of vertex N[" << i + 1 << "]:" << endl;
            for (int t = 0; t < 4; t++){
                arr[t].printPoint();
            }
            cout << " Volume: " << V << endl;
            if(i==0){
                max = V;
                ind = i;
            }else if(max<V && i>0){
                max = V;
                ind = i;
            }
            flag = true;
            cout << "\tPress 'ENTER' to continue, another key to stop..." << endl;
            ch = _getch();
        }
        i++;
        if(i==30){cout<<"You can generate only 30 object !!!"<<endl; break; }
    } while (ch == 13 || !flag );
}

void task(Point* arr, Tetraedr* objArr, bool &flag, float &max, int &ind) {
    int i=0;
    do{
        fill(arr);
        cout << " Coordinates of vertex N[" << i + 1 << "]:" << endl;
        for (int t = 0; t < 4; t++) {
            arr[t].printPoint();
        }

        objArr[i]= Tetraedr(arr);
        float V = objArr[i].getV();
        if (V == 0) {
            cout << " Object doesn't exist...." << endl;
        }
        else {
            cout << " Volume: " << V << endl;
            if(V>0 && i==0){
                max = V;
                ind = i;
            }else if(max<V && i>0){
                max = V;
                ind = i;
            }
            flag = true;
        }
                i++;
                cout << "\tPress 'ENTER' to continue, another key to stop..." << endl;
        if(i==30){ cout<<"You can enter only 30 object !!!"<<endl; break; }
    } while (_getch() == 13);
}

void displayRes(float V, int i, bool flag){
    if(flag){
        cout<< " Object with max volume is N["<<i+1<<"]"<<endl<<" Volume = "<< V <<endl;
    }else{
        cout<<"--- All of the objects from list don't have volume!!! ---"<<endl;
    }
}
>>>>>>> bfeba72 (1)
