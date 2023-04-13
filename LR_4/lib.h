#include<iostream>
using namespace std;

class Date{
    int d, m, y, day_diff, mon_diff, year_diff;
public:
    Date(){d=0;m=0;y=0;}
    Date(int dd, int mm, int yy):d(dd), m(mm), y(yy){}
    Date(int dd, int mm):d(dd), m(mm), y(2023){}
    Date operator+=(int value);
    Date operator-(Date other);
    void getDate(int& dd, int& mm, int& yy);
    void getDiff(int& dd, int& mm, int& yy);
    string season();
    void print();
};

void enterDate(Date *arr);
bool checkOrder(Date D1, Date D2);
void displayInput(Date *arr);
void handleD1andD2(Date *arr);
void handleD3(Date *arr);