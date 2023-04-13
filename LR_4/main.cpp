#include<iostream>
#include<conio.h>
#include"lib.h"
using namespace std;

int main(){
    do {
        int size = 10;
        Date *arr = new Date[size];
        enterDate(arr);
        displayInput(arr);
        handleD1andD2(arr);
        handleD3(arr);
        delete[] arr;
        string message = " Press ENTER to run again, ESC to exit...";
        cout<<endl<<message<<endl;
    }while(_getch()==13);
    return 0;
}

