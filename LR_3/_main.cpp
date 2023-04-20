<<<<<<< HEAD
#include<iostream>
#include<ctime>
#include<conio.h>
#include"classlib.h"
const int m = 30;
using namespace std;

int main() {
    do {
        srand(time(nullptr));
        cout << "\t--------- Program will find the object with max volume [30 objects - max] ---------\t" << endl;
        Point arr[m]; Tetraedr objArr[m];
        float maxVolume; int index;
        bool flag = false;
        int res = answ();
        if (res == 1){
            task(arr, objArr, maxVolume, index);
            flag = true;
        } else {
            task(arr, objArr, flag, maxVolume, index);
        }
        displayRes(maxVolume, index, flag);
        cout<<endl<<"\tPress ENTER to run again, ESCAPE to exit"<<endl;
    }while(_getch() == 13 );
    return 0;
}


=======
#include<iostream>
#include<ctime>
#include<conio.h>
#include"classlib.h"
using namespace std;

int main() {
    do {
        srand(time(nullptr));
        cout << "\t--------- Program will find the object with max volume ---------\t" << endl;
        Point arr[100];
        Tetraedr objArr[100];
        float maxVolume;
        int index,  i = 0;
        bool flag = false;
        int res = answ();
        if (res == 1) {
            task(arr, objArr, maxVolume, index,i);
            displayRes(maxVolume, index, true);
        } else {
            do {
                fill(arr);
                task(arr, objArr, flag, maxVolume, index,i);
                i++;
                cout << "\tPress 'ENTER' to continue, another key to stop..." << endl;
            } while (_getch() == 13);
            displayRes(maxVolume, index, flag);
        }
        cout<<endl<<"\tPress ENTER to run again, ESCAPE to exit"<<endl;
    }while(_getch() == 13 );
    return 0;
}


>>>>>>> bfeba72 (1)
