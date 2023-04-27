#include "functions.h"
#include <iostream>
#include<cmath>
#include<sstream>
using namespace std;
void VectorR2::print(){
    cout<<" ("<<A.getX()<<", "<<A.getY()<<")"<<endl;
}

float VectorR2::lenV(){
    return sqrt(pow(A.getX(), 2) + pow(A.getY(), 2));
}

float VectorR2::scalarProduct(Point other) {
    return (A.getX()*other.getX()+A.getY()*other.getY());
}

void VectorR3::print() {
    cout<<" ("<<A.getX()<<", "<<A.getY()<<", "<<A.getZ()<<")"<<endl;
}

float VectorR3::lenV() {
    return sqrt(pow(A.getX(), 2) + pow(A.getY(), 2) +pow(A.getZ(), 2));
}

float VectorR3::scalarProduct(Point other) {
    return (A.getX()*other.getX()+A.getY()*other.getY()+A.getZ()*other.getZ());
}

Point readInputR3(){
    bool invalid = true;
    float num1, num2, num3;
    do {
        string input;
        getline(cin, input);
        cin.clear();
        stringstream ss(input);
        if (ss >> num1 >> num2 >> num3) {
            invalid=false;
        } else {
            invalid=true;
            cout << "Invalid input format.\n";
        }
    }while(invalid);
    return Point(num1, num2, num3);
}

Point readInputR2(){
    bool invalid;
    do {
        cin.clear();
        string input;
        getline(cin, input);
        std::stringstream ss(input);
        float num1, num2;
        if (ss >> num1 >> num2) {
            invalid=false;
            return Point(num1, num2);
        } else {
            std::cout << "Invalid input format.\n";
            invalid=true;
        }
    }while(invalid);
}

Point fillR3(bool flag){
    if(flag){
        cout<<" Enter data as string[num1 num2 num3]:";
        Point X = readInputR3();
        return X;
    }else{
        return Point(rand()%100, rand()%100, rand()%100);
    }
}

Point fillR2(bool flag){
    if(flag){
        cout<<" Enter data as string[num1 num2]:";
        Point X = readInputR2();
        return X;
    }else{
        return Point(rand()%100, rand()%100, rand()%100);
    }
}

bool getMode(){
    cout<<" Generate array or fill manually?[G/M]:"<<endl;
    char answ;
    cin>>answ;
    fflush(stdin);
    return answ!='G'&&answ!='g';
}