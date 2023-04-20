
#include"lib.h"
#include"validation.h"
#include<iomanip>

Date Date::operator+=(int value) {
    d = d + value;
    int n = d/31;
    if(n<0) n=1;
    int i=0;
    while(i<n){
        if (d > 31 && (m!=2 && m!=4 && m!=9 && m!=11)) {
            d = d - 31; m++;
        } else if (d > 30 && (m == 4 || m == 6 || m == 9 || m == 11)) {
            d = d - 30; m++;
        } else if (d > 29 && (m == 2 && isLeap(y))) {
            d = d - 29; m++;
        } else if (d > 28 && (m == 2 && !isLeap(y))) {
            d = d - 28; m++;
        }
        i++;
    }

    if(m>12){
        m = m-12;
        y++;
    }
    return *this;
}

Date Date:: operator-(Date other){
    int day_diff, mon_diff, year_diff;
    if (other.d < d) {
        if (other.m == 2) {
            //if ((other.y % 4 == 0 && other.y % 100 != 0) || (other.y % 400 == 0)) {
            if(isLeap(other.y)){
                other.d += 29;
            } else {
                other.d += 28;
            }
        } else if (other.m == 5 || other.m == 7 || other.m == 10 || other.m == 12) {
            other.d += 30;
        } else {
            other.d += 31;
        }
        other.m = other.m - 1;
    }

    if (other.m < m){
        other.m += 12;
        other.y -= 1;
    }

    day_diff = other.d - d;
    mon_diff = other.m - m;
    year_diff = other.y - y;

    Date diff(day_diff, mon_diff, year_diff);
    return diff;
}

void Date:: getDate(int& dd, int& mm, int& yy){
    dd=d; mm=m; yy=y;
}

string Date:: season(){
    if(m==1 || m== 2 || m==12){
        return "Winter";
    }else if(m==4 || m==5 || m==3){
        return "Spring";
    }else if(m==6 || m==7 || m==8){
        return "Summer";
    }else{
        return "Autumn";
    }
}

void Date:: print() {
    cout<<setw(2)<<setfill('0')<<right<<d<<"."
        <<setw(2)<<setfill('0')<<right<<m<<"."<<y<<endl;
}

void enterDate(Date *arr){
    cout<<" <--- Enter date [dd/mm/yyyy], yy is optional --->"<<endl;
    for(int i=0; i<3; i++){
        bool flag = false;
        int d, m, y;
        cout<<endl<<" D"<<i+1<<": ";
        validateInput(d, m, y, flag);
        if(flag){
            arr[i]= Date(d, m);
        }else{
            arr[i]= Date(d, m, y);
        }
    }
}

bool checkOrder(Date D1, Date D2){
    int d1, d2, m1, m2, y1, y2;
    D1.getDate(d1, m1, y1);
    D2.getDate(d2, m2, y2);
    return !(y1>y2 || (y1==y2 && m1>m2) || (y1==y2 && m1==m2 && d1>d2));
}

void displayInput(Date *arr){
    cout<<endl<<" Entered data:"<<endl;
    for (int i = 0; i < 3; i++) {
        cout << " D" << i + 1 << ' ';
        arr[i].print();
    }
}

void handleD1andD2(Date *arr){
    Date diff;
    cout << " ----------------------------------------" << endl<< endl;
    arr[0] += 9;
    cout << " D1 after adding 9 days: ";
    arr[0].print();

    arr[1] += 14;
    cout << " D2 after adding 14 days: ";
    arr[1].print();

    cout << endl <<" ----------------------------------------" << endl<< endl;

    bool checker = checkOrder(arr[0], arr[1]);
    if(!checker){
        diff = arr[1] - arr[0];
    }else{
        diff = arr[0] - arr[1];
    }

    int dD = 0, dM = 0, dY = 0;
    diff.getDate(dD, dM, dY);
    cout <<" Difference between D1 and D2: "<<endl
         <<" "<<dD<< " day(s), "<<dM<<" month(es)";
    if (dY>0) cout<<", "<<dY<< " year(s)" << endl << endl;
    else cout<<endl<<endl;
}

void handleD3(Date *arr){
    cout << " ----------------------------------------" << endl;
    string s = arr[2].season();
    cout << " The season of D3 is " << s << endl;
}
