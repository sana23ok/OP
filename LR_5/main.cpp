#include<iostream>
#include<cmath>
#include<conio.h>
#include"functions.h"
using namespace std;

//find S = <a,b>+<c,b>+|a|
//a, b Є R^3; c, d Є R^2
int main(){
    do {
        srand(time(nullptr));
        int n = 2;
        char nR2[] = {'c', 'd'}, nR3[] = {'a', 'b'};
        bool flag = getMode();
        TVector *baseVector2[n], *baseVector3[n];//baseVector2[n]-R2, baseVector3[n]-R3

        VectorR3 *A2 = new VectorR3[n];
        for (int i = 0; i < n; i++) {
            baseVector3[i] = &A2[i];
            Point X = fillR3(flag);
            A2[i] = VectorR3(X);
            baseVector3[i]->print();
            cout << " Len of vector " << nR3[i] << " = " << baseVector3[i]->lenV() << endl;
        }

        VectorR2 *A1 = new VectorR2[n];
        for (int i = 0; i < n; i++) {
            baseVector2[i] = &A1[i];
            Point X = fillR2(flag);
            A1[i] = VectorR2(X);
            baseVector2[i]->print();
            cout << " Len of vector " << nR2[i] << " = " << baseVector2[i]->lenV() << endl;
        }

        float res1 = baseVector3[0]->scalarProduct(baseVector3[1]->getP());
        cout <<endl<< " <a,b> = " << res1 << endl;

        float res2 = baseVector2[0]->scalarProduct(baseVector2[1]->getP());
        cout << " <c,b> = " << res2 << endl;

        float S = res1 + res2 + (baseVector3[0]->lenV());
        cout << " |a| = " << baseVector3[0]->lenV() << endl;
        cout << " S = <a,b>+<c,b>+|a|" << endl;
        cout << " S = " << S << endl;

        delete[] A1;
        delete[] A2;
        string message = " Press ENTER to run again, ESC to exit...";
        cout<<endl<<message<<endl;
    }while(_getch()==13);
    return 0;
}
