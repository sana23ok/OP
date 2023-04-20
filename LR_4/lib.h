<<<<<<< HEAD
#include<iostream>
using namespace std;

class Date{
    int d, m, y;
public:
    Date(){d=0;m=0;y=0;}
    Date(int dd, int mm, int yy):d(dd), m(mm), y(yy){}
    Date(int dd, int mm):d(dd), m(mm), y(2023){}
    Date operator+=(int value);
    Date operator-(Date other);
    void getDate(int& dd, int& mm, int& yy);
    string season();
    void print();
};

void enterDate(Date *arr);
bool checkOrder(Date D1, Date D2);
void displayInput(Date *arr);
void handleD1andD2(Date *arr);
=======
#include<iostream>
using namespace std;

class Date{
    int d, m, y;
public:
    Date(){d=0;m=0;y=0;}
    Date(int dd, int mm, int yy):d(dd), m(mm), y(yy){}
    Date(int dd, int mm):d(dd), m(mm), y(2023){}
    Date operator+=(int value);
    Date operator-(Date other);
    void getDate(int& dd, int& mm, int& yy);
    string season();
    void print();
};

void enterDate(Date *arr);
bool checkOrder(Date D1, Date D2);
void displayInput(Date *arr);
void handleD1andD2(Date *arr);
>>>>>>> fd635a8 (new conmit)
void handleD3(Date *arr);