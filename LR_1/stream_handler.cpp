#include"stream_handler.h"
#include"pointer_handler.h"
#include<iostream>
#include<fstream>
#include<string>
#include<filesystem>
const int MAX = 255;
using namespace std;

string start(){
    cout<<"Enter the name of the file:";
    string name;
    cin>>name;
    return name;
}

int checkFile(const string& filename){
    if (filesystem::exists(filename)) {
        cout << "The file exists!" <<endl;
        return 1;
    } else {
        return 0;
    }
}

void writeInFile(ofstream &file){
    cout<<"\nEnter records in file:(press 'Enter' and '*' if you want to stop):"<<endl;
    string line;
    int iter=0;
    if(file.is_open()){
        cin.ignore(256, '\n');
        do{
            //cout<<"\nLine["<<iter+1<<"]:"<<endl;
            getline(cin, line);
            if(line == "*") break;
            file<<line<<endl;
            iter++;
        }while(1);
    }else{
        cout<<"Unable to write in file..."<<endl;
    }
}

void readFromFile(string namefile){
    ifstream file;
    file.open(namefile);
    string line;
    int iter=1;
    char dot = '.';
    if(file.is_open()){
        while (getline(file, line)){
            cout << iter << dot << line << endl;
            iter++;
        }
    }else{
        cout<<"An error of opening the file"<<endl;
    }
    file.close();
}

string strClear(string &s){
    int j=0;
    //int size = s.size();
    while (s[j]) {
        s[j] = tolower(s[j]);
        j++;
    }

    for (int i = 0, len = s.size()+1; i < len; i++)
    {
        if (ispunct(s[i]))
        {
            s.erase(i--, 1);
            len = s.size();
        }
    }
    //cout<<"Cleared: "<< s <<endl;
    return s;
}

void compare(string arr[], int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(arr[i]<arr[j]){
                string temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

string rearange(string str){
    string splited[MAX];
    istringstream ss(str);
    string del;
    int i=0;
    while(getline(ss, del, ' ')) {
        splited[i] = del;
        i++;
    }

    compare(splited, i+1);
    cout<<endl;
    string ordered;
    for(int k=0; k<i+1; k++){
        ordered += splited[k];
        if(k!= i+1){
            ordered += " ";
        }
    }
    //cout<<"ordered: "<< ordered <<endl;
    return ordered;
}

int checkPunct(string A){
    int i=0;
    int size= A.size();
    int res;
    if(islower(A[0])){
        res = 0;
    } else{
        do {
            if ((A[i] == '.' || A[i] == '?' || A[i] == '!') && (i != size-1)) {
                res = 0;
                break;
            }else if ((A[i] == '.' || A[i] == '?' || A[i] == '!') && (i == size-1)) {
                res = 1;
            } else{
                res = 0;
            }
            i++;
        }while(i<size);
    }
    return res;
}

void startEditing(string path){
    ofstream file;
    file.open(path, ios::app);
    cout<<"Enter the line that you want to append:\n";
    string line;
    if(file.is_open()){
        cin.ignore(256, '\n');
        getline(cin, line);
        file<<line<<endl;
    }else{
        cout<<"Unable to write in file..."<<endl;
    }
}

void edit(string path){
    char ch = 'y';
    do{
        cout<<"Do you want to add text to the file?[y/n]";
        cin>>ch;
        if((ch!='y')&&(ch!='Y')) break;
        startEditing(path);
    }while(true);
}

void task(string path){
    if(checkFile(path)==0){
        ofstream output;
        output.open(path);
        writeInFile(output);
        readFromFile(path);
        output.close();
    }

    ifstream file;
    file.open(path);
    cout<<"\n--------------Records----------------\n";
    if(file.is_open()) readFromFile(path);
    else cout<<"Error of reading the file";
    file.close();
}

void createNewFile(const string& name){
    string path= name + ".txt", path_new = name + "_new.txt";

    ifstream infile;
    infile.open(path);

    ofstream newfile;
    newfile.open(path_new);

    if(infile.is_open()) {
        string line;
        int iter = 0;
        while (getline(infile, line)){
            int check = checkPunct(line);
            if((iter%2==0||iter==0) && check){
                strClear(line);
                line = rearange(line);
                //cout<<line<<endl;
                newfile<<line<<endl;
            }
            iter++;
        }
    }

    readFromFile(path_new);

    newfile.close();
    infile.close();
}

void startStreamHandling(){
    string name = start();
    string path = name + ".txt";
    //open for writing in file
    task(path);
    edit(path);
    cout<<endl<<"----------------Records----------------"<<endl;
    createNewFile(name);
}
