class Point{
    float x, y, z;
public:
    Point(){};
    Point(float xx, float yy, float zz=0): x(xx), y(yy), z(zz){};
    float getX(){return x;}
    float getY(){return y;}
    float getZ(){return z;}
};

class TVector{
protected:
    Point A;
public:
    virtual float lenV()=0;
    virtual float scalarProduct(Point)=0;//для знаходження скалярного добутку векторів
    virtual void print()=0;
    Point getP() { return A;}
};

class VectorR2: public TVector{
public:
    VectorR2(){};
    VectorR2(Point other){
        A=other;
    }
    float lenV() override;
    float scalarProduct(Point other) override;
    void print() override;
};

class VectorR3: public TVector{
public:
    VectorR3(){};
    VectorR3(Point B){
        A=B;
    };
    float scalarProduct(Point other) override;
    float lenV() override;
    void print() override;
};


Point readInputR3();

Point readInputR2();

Point fillR3(bool flag);

Point fillR2(bool flag);

bool getMode();