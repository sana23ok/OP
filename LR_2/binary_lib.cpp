#include<iostream>
#include<cstring>
#include<fstream>
#include<iomanip>
#include<cmath>
#include<chrono>
#include<filesystem>
#include<conio.h>
#include"binary_lib.h"
#include"validation.h"
using namespace std;

typedef struct D;
typedef struct T;
typedef struct Med;

string fileName(){
    cout<<"Enter the name of file (without extension):";
    string name;
    getline(cin, name);
    return name;
}

string getName() {
    cout << "Name of vial:";
    string line;
    getline(cin, line);
    fflush(stdin);
    return line;
}

T getTime(int signal) {
    T time{};
    bool flag;
    do{
        cout << "[hh:mm]:";
        string exp;
        cin >> exp;
        fflush(stdin);
        int parsed = sscanf(exp.c_str(), "%d:%d\n", &time.hours, &time.minutes);
        if (parsed != 2) {
            cout << "\nInvalid input... Try again....\n";
            flag = false;
        }else{
            if(signal == 1 && (time.hours<0 || time.hours >24)){
                cout<<"Value of hours must be in (0, 24)!!!\n";
                flag =  false;
            }else if(signal == 0 && (time.hours < 0 || time.hours > 100) ){
                cout<<"Value of hours must be in (0, 100)!!!\n";
                flag =  false;
            }else if(time.minutes<0 || time.minutes >60 ){
                cout<<"Value of minutes must be in (0, 60)!!!\n";
                flag =  false;
            }else{
                flag = true;
            }
        }
    }while(!flag);
    return time;
}

D getDate() {
    cout << "[dd.mm.yyyy]:";
    D date{};
    bool flag;
    string exp;
    do {
        cin >> exp;
        fflush(stdin);
        int parsed = sscanf(exp.c_str(), "%d.%d.%d\n", &date.day, &date.month, &date.year);
        if (parsed != 3) {
            cout << "\nInvalid input... Try again....\n";
            flag = false;
        } else {
            if(!day_is_valid(date.day, date.month, date.year)|| !month_is_valid(date.month) || !year_is_valid(date.year)){
                cout<<"Invalid input.. Try again...\n";
                flag = false;
            }else{
                flag = true;
            }
        }
    }while(!flag);
    return date;
}

int getExp() {
    cout << "Expiration date [years]:";
    int exp = validateExp();
    return exp;
}

vial enterData() {
    vial a[MAX];
    const char *name = getName().c_str();
    strcpy(a->name, name);
    cout << "Shelf-life after opening\n";
    a->time = getTime(0);
    a->exp = getExp();
    return *a;
}

void fillFile(ofstream &file, Med ampula[]) {
    cout <<"\nFill the information about vials\n[press 'Enter' to continue, another key to stop]:\n";
    int i = 0;
    do {
        cout << "Vial N" << i + 1 << ":" << endl;
        ampula[i] = enterData();
        file.write((char *) &ampula[i], sizeof(Med));
        i++;
    }while (getch()==13);
}

void display(const string& name, Med ampula[], int &j){
    ifstream file(name, ios::binary|ios::in);
    j = 0;
    cout << "--------------------------------------------------------------------------------\n";
    cout << " List of medication:\n\n";
    cout<<" N "<<"\t"<<left<<"Name    "<<"\t\t\t"<<"Shell life   "<<"\t\t"<<"Years of   "<<endl;
    cout<<"  \t"<<left<<"of vial    "<<"\t\t\t"<<"after opening "<<"\t\t"<<"shell life "<<endl;
    cout << "--------------------------------------------------------------------------------\n";
    while (file.read((char *) (&ampula[j]), sizeof(Med))){
        cout<<" "<<(j+1)<<".\t "<<left<<setw(15)<<setfill(' ')<<ampula[j].name<<"\t\t "<<right<<setw(2)<<setfill('0')<<ampula[j].time.hours<<
            ":"<<right<<setw(2)<<setfill('0')<<ampula[j].time.minutes<<setw(2)<<"\t\t\t  "<<ampula[j].exp<<endl;
        j++;
    }
    cout << "\n--------------------------------------------------------------------------------\n";
    file.close();
}

void displayNew(const string& name, Med ampula[], bool flag) {
    if(!flag){
        cout << "\n------------------------------------------------------------------------------------------\n";
        cout<<"The list of vials that can be used is empty!"<<endl;
    }else{
        ifstream file(name, ios::binary | ios::in);
        int j = 0;
        int n=1;
        cout << "\n-----------------------------------------------------------------------------------------\n";
        cout << "List of opened medication:\n";

        cout<<" N "<<"\t"<<left<<" Name    "<<"\t\t\t"<<"Time       "<<"\t\t\t"<<"Use before the "<<endl;
        cout<<"   \t"<<left    <<" of vial "<<"\t\t\t"<<"of opening "<<"\t\t\t"<<"indicated date "<<endl<<endl;
        while (file.read((char*)(&ampula[j]), sizeof(Med)) && file.read((char*)(&ampula[j+1]), sizeof(Med))){
            int k = j+1;
            cout<<" "<<n<<".\t "<<left<<setw(15)<<setfill(' ')<<ampula[j].name<<"\t\t"<<right<<setw(2)<<setfill('0')<<ampula[j].time.hours<<
                ":"<<right<<setw(2)<<setfill('0')<<ampula[j].time.minutes<<"\t"<<
                right<<setw(2)<<setfill('0')<<ampula[j].date.day<<"."<<
                right<<setw(2)<<setfill('0')<<ampula[j].date.month<<"."<<ampula[j].date.year;
            cout<<"\t\t"<<right<<setw(2)<<setfill('0')<<ampula[k].time.hours<<
                ":"<<right<<setw(2)<<setfill('0')<<ampula[k].time.minutes<<"\t"<<
                right<<setw(2)<<setfill('0')<<ampula[k].date.day<<"."<<
                right<<setw(2)<<setfill('0')<<ampula[k].date.month<<"."<<ampula[k].date.year<<endl;
            j+=2;
            n+=1;
        }
        cout << "\n-----------------------------------------------------------------------------------------\n";
        file.close();
    }
}

float calulateDiff(vial opened[], int i){
    int hour = opened[i].time.hours;
    int minute = opened[i].time.minutes;
    int day = opened[i].date.day;
    int month = opened[i].date.month;
    int year = opened[i].date.year;

    tm start = {0};
    start.tm_hour = hour;
    start.tm_min = minute;
    start.tm_mday = day;
    start.tm_mon = month - 1;
    start.tm_year = year - 1900;

    time_t start_time = mktime(&start);
    chrono::system_clock::time_point now = chrono::system_clock::now();
    time_t now_time = chrono::system_clock::to_time_t(now);
    double diff_seconds = difftime(now_time, start_time);
    //cout<<"Time diff: "<< diff_seconds/60 <<endl;
    return float(diff_seconds);
}

vial calulateEnd(vial ampula[], vial opened[], int n, int i){
    int hh = ampula[n].time.hours;
    int mm = ampula[n].time.minutes;

    int hour = opened[i].time.hours;
    int minute = opened[i].time.minutes;
    int day = opened[i].date.day;
    int month = opened[i].date.month;
    int year = opened[i].date.year;

    int dayA = floor((hh+hour)/24);
    int hourA = hh - (dayA*24);
    int minA = minute+mm;
    int plus = floor((hh+hour)/24);

    if((hour+hourA)>=24){
        hourA = (hour+hourA) - plus*24;
        dayA += 1;
    }

    if((minA)>=60){
        minA = (mm+minute)-60;
        hourA += 1;
    }

    //cout<<endl<<"use till "<< hour+hourA <<":"<<minA<<" "<<day+dayA<<"/"<<month<<"/"<<year<<endl;
    opened[i].time.hours = hour+hourA;
    opened[i].time.minutes = minA;
    opened[i].date.day = day+dayA;
    opened[i].date.month = month;
    opened[i].date.year =year;
    return *opened;
}

void task(string name, vial ampula[], int k){
    Med opened[MAX];
    bool flag = false;
    string newName = "new_"+name;
    ofstream file(newName, ios::binary | ios::out );
    int i=0;
    do {
        int n= opVial(k);
        n -= 1;
        cout << "\nTime of opening ";
        strcpy(opened[i].name, ampula[n].name);
        opened[i].time = getTime(1);
        opened[i].date = getDate();
        float diff = calulateDiff(opened, i);
        //cout<<diff<<endl;
        if((diff/60)<float(ampula[n].time.hours*60 + ampula[n].time.minutes)){
            flag = true;
            file.write((char *)&opened[i], sizeof(Med));
            opened[i] = calulateEnd(ampula, opened, n, i);
            file.write((char *)&opened[i], sizeof(Med));
        }
        cout << "Add another opened vial?[Y/N]";
        char answ;
        cin >> answ;
        cin.ignore();
        if ((answ != 'y') && (answ != 'Y')) break;
    }while(true);
    file.close();
    displayNew(newName, ampula, flag);
}

void addLine(string path, int &i){
    ofstream file(path, ios::binary | ios::out | ios::app);
    Med a[MAX];
    if (file){
        a[i] = enterData();
        file.write((char *) &a[i], sizeof(Med));
    } else {
        cout << "Error of opening a file..." << endl;
    }
    file.close();
}

void edit(string path, vial ampula[], int &count){
    do {
        cout << "Add another line to the list?[Y/N]\n";
        char answ;
        cin >> answ;
        cin.ignore();
        if ((answ != 'y') && (answ != 'Y')) break;
        addLine(path, count);
        count++;
    }while(true);
    display(path, ampula, count);
}

int checkEx(const string& fname){
    int checker;
    if (filesystem::exists(fname)){
        cout<<"\n\t\t--The file already exists!--\t\t\n";
        checker = 1;
    }else{
        checker = 0;
    }
    return checker;
}

int len() {
    string num;
    int invalid = 0;
    do {
        cout << "Enter a number of vials:";
        cin >> num;
        cin.ignore();

        for (char i : num) {
            if (!isdigit(i)) {
                cout << "Invalid input enter digit number. Try again...\n";
                invalid = 1;
            }
        }
    }while(invalid);
    return stoi(num);
}