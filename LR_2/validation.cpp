<<<<<<< HEAD
#include<iostream>
#include<cstdio>
#include"validation.h"

int check_leap(int year){
    return (year % 100 != 0 && year % 4 == 0) || (year % 100 == 0 && year % 400 == 0);}

bool day_is_valid(int day, int month, int year){
    bool flag;
    bool leap = check_leap(year);
    if((day<1) || (day>31)){
        flag = false;
    }else if(day>30 && (month == 4 || month == 6 || month == 7 || month == 9 || month == 11)){
        flag = false;
    }else if((leap==1 && month==2) && day>29){
        flag = false;
    }else if((leap!=1 && month==2) && day>28) {
        flag = false;
    }else{
        flag = true;
    }
    return flag;
}

bool month_is_valid(int m){
    bool fl = true;
    if(m<1 || m>12){
        fl = false;
    }
    return fl;
}

bool year_is_valid(int y){
    bool fl = true;
    if(y<0){
        fl = false;
    }
    return fl;
}

int opVial(int j){
    int v;
    char c;
    bool flag;
    do{
        std::cout<<"\nChose opened vial:";
        scanf("%d%c", &v, &c);
        fflush(stdin);
        if(c != '\n'){
            std::cout<<"Invali input";
            flag = false;
        }else{
            if(v>j || v<1){
                flag = false;
                std::cout<<"You can chose number from interval [1, "<<j<<"]"<<std::endl;
            }else{
                flag = true;
            }
        }
    }while(!flag);
    return v;
}

int validateExp(){
    int num;
    char c;
    bool flag;
    do{
        scanf("%d%c", &num, &c);
        fflush(stdin);
        if(c != '\n'){
            std::cout<<"Invali input... Try again..."<<std::endl;
            flag = false;
        }else{
            if(num<1){
                flag = false;
                std::cout<<"Invali input... Try again..."<<std::endl;
            }else{
                flag = true;
            }
        }
    }while(!flag);
    return num;
=======
#include<iostream>
#include<cstdio>
#include"validation.h"

int check_leap(int year){
    return (year % 100 != 0 && year % 4 == 0) || (year % 100 == 0 && year % 400 == 0);}

bool day_is_valid(int day, int month, int year){
    bool flag;
    bool leap = check_leap(year);
    if((day<1) || (day>31)){
        flag = false;
    }else if(day>30 && (month == 4 || month == 6 || month == 7 || month == 9 || month == 11)){
        flag = false;
    }else if((leap==1 && month==2) && day>29){
        flag = false;
    }else if((leap!=1 && month==2) && day>28) {
        flag = false;
    }else{
        flag = true;
    }
    return flag;
}

bool month_is_valid(int m){
    bool fl = true;
    if(m<1 || m>12){
        fl = false;
    }
    return fl;
}

bool year_is_valid(int y){
    bool fl = true;
    if(y<0){
        fl = false;
    }
    return fl;
}

int opVial(int j){
    int v;
    char c;
    bool flag;
    do{
        std::cout<<"\nChose opened vial:";
        scanf("%d%c", &v, &c);
        fflush(stdin);
        if(c != '\n'){
            std::cout<<"Invali input";
            flag = false;
        }else{
            if(v>j || v<1){
                flag = false;
                std::cout<<"You can chose number from interval [1, "<<j<<"]"<<std::endl;
            }else{
                flag = true;
            }
        }
    }while(!flag);
    return v;
}

int validateExp(){
    int num;
    char c;
    bool flag;
    do{
        scanf("%d%c", &num, &c);
        fflush(stdin);
        if(c != '\n'){
            std::cout<<"Invali input... Try again..."<<std::endl;
            flag = false;
        }else{
            if(num<1){
                flag = false;
                std::cout<<"Invali input... Try again..."<<std::endl;
            }else{
                flag = true;
            }
        }
    }while(!flag);
    return num;
>>>>>>> bfeba72 (1)
}