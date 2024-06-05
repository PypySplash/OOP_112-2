#include <iostream>
using namespace std;
#include <vector>
#include <cmath>

const double pi = 3.1415926;

class Shape
{
public:
    virtual double getArea() = 0;
    virtual string getClassName() = 0;
    virtual ~Shape() = default;
};



class Rectangle : public Shape
{
private:
    double len;
    double wid;
public:
    Rectangle(double l, double w) : len(l), wid(w) {}
    double getArea()
    {
        return len * wid;
    }
    string getClassName()
    {
        return "Rectangle";
    }
};
class Circle : public Shape
{
private:
    double rad;
public:
    Circle(double r) : rad(r) {}
    double getArea()
    {
        return pi * pow(rad, 2);
    }
    string getClassName()
    {
        return "Circle";
    }
};
class Triangle : public Shape
{
private:
    double a;
    double b;
    double c;
public:
    Triangle(double a, double b, double c) : a(a), b(b), c(c) {}
    double getArea()
    {
        double s;
        s = (a + b + c) / 2;
        return pow(s * (s - a) * (s - b) * (s - c), 0.5);
    }
    string getClassName()
    {
        return "Triangle";
    }
};



ostream& operator<<(ostream& out, Shape* shape)
{
    out << shape->getClassName() << "'s area is " << shape->getArea() << endl;
    return out;
}



int main() {
vector<Shape*> vs;
Rectangle r(10,20);
Circle c(10);
Triangle t(18,30,24);
vs.push_back(&r);
vs.push_back(&c);
vs.push_back(&t);
for (auto s : vs)
    cout << s;
}
