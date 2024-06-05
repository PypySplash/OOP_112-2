#include <iostream>
using namespace std;
#include <vector>
#include <cmath>



class Shape
{
private:
    int side1;
    int side2;
    int side3;
public:
    Shape() = default;
    virtual double getArea() = 0;
    virtual string getClassName() = 0;
    friend ostream& operator<<(ostream& cout, Shape* shape) 
    {
        cout << shape->getClassName() << "'s area is " << shape->getArea() << endl;
        return cout;
    }
};

class Triangle : public Shape
{
private:
    int side1;
    int side2;
    int side3;
public:
    Triangle(int s1, int s2, int s3) : side1(s1), side2(s2), side3(s3) {}
    double getArea() override
    {
        // 計算半周長
        double s = (side1 + side2 + side3) / 2.0;
        // 使用海龍公式計算面積
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }
    string getClassName() override {return "Triangle";}
};

class Circle : public Shape
{
private:
    int radius;
public:
    Circle(int r) : radius(r) {}
    double getArea() override
    {
        return 3.1415 * pow(radius, 2);
    }
    string getClassName() override {return "Circle";}
};



class Rectangle : public Shape
{
private:
    int length;
    int width;
public:
    Rectangle(int l, int w) : length(l), width(w) {}
    double getArea() override
    {
        return length * width;
    }
    string getClassName() override {return "Rectangle";}
};



int main(){
vector<Shape*> vs;
Rectangle r(10,20);
Circle c(10);
Triangle t(18,30,24);
vs.push_back(&r);
vs.push_back(&c);
vs.push_back(&t);
for(auto s : vs)
cout << s;
}
