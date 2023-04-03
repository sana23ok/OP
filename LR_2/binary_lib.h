const int MAX = 255;
using namespace std;
typedef struct D{
    int day;
    int month;
    int year;
};
typedef struct T{
    int hours;
    int minutes;
};
typedef struct Med{
    char name[MAX];
    T time{};
    D date{};
    int exp;
}vial;
string fileName();
string getName();
T getTime();
D getDate();
int getExp();
vial enterData();
void fillFile(ofstream&, Med[]);
void display(const string&, Med[], int&);
void displayNew(const string&, Med[], bool);
int check_leap(int);
float calulateDiff(vial[], int);
vial calulateEnd(vial[], vial[], int, int);
void task(string, vial[], int);
void addLine(string, int&);
void edit(string, vial[], int&);
int checkEx(const string&);