#include <iostream>
#include <conio.h>
#include "my_ADT.h"
using namespace std;

int main() {
    do {
        int type = choice();
        if (type == 1) {
            Set<int> A = createAndFillSet<int>();
            Task(A);
        } else if (type == 2) {
            Set<float> A = createAndFillSet<float>();
            Task(A);
        } else if (type == 3) {
            Set<char> A = createAndFillSet<char>();
            Task(A);
        } else if (type == 4) {
            Set<string> A = createAndFillSet<string>();
            Task(A);
        } else {
            cerr << "Unexpected type!" << endl;
        }
        cout <<endl<< " Press Enter to continue or Esc to exit... "<<endl;
    } while (_getch() == 13);
    return 0;
}
