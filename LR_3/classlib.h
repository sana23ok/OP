#pragma once
#include<iostream>
#include<cmath>
class Point {
    float x, y, z;
public:
    Point() {}
    Point(float x, float y, float z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    void getPoint(float& xx, float& yy, float& zz);
    void printPoint();
};

class Tetraedr {
    float volume();
public:
    Point obj[4];
    Tetraedr() {}
    Tetraedr(Point* obj) {
        for (int i = 0; i < 4; i++) {
            this->obj[i] = obj[i];
        }
    }
    float getV() {
        return (fabs(volume()/6));
    }
};

int answ();
void generate(Point*);
void fill(Point*);
void task(Point*, Tetraedr*, bool&, float&, int&);
void task(Point*, Tetraedr*, float&, int&);

