#include<iostream>
#include<fstream>
#include<conio.h>
#include"binary_lib.h"

int main(){
    do{
        Med ampula[MAX];
        int j=0;
        string filename = fileName();
        int res = checkEx(filename);
        ofstream file(filename, ios::binary|ios::out|ios::app);
        if (res == 0) fillFile(file, ampula);
        file.close();
        display(filename, ampula, j);
        edit(filename, ampula, j);
        task(filename, ampula, j);
        cout<<"Press 'Enter' to run again, 'Esc' to quit"<<endl;
    }while(getch()!=27);
    return 0;
}