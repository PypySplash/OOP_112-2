#include <iostream>
using namespace std;
#include <vector>
#include <cmath>

const double pi = 3.1415926;



class Shape
{
public:
    virtual void getArea() = 0;
    virtual void getClassName() = 0;
    virtual ~Shape() {}; 
};




class Rectangle : public Shape
{
private:
    double len;
    double wid;
public:
    Rectangle(double l, double w) : len(l), wid(w)
    {
        // cout << getClassName() << " of id ";
    }
    void getArea()
    {
        cout << len * wid << endl;
    }
    void getClassName()
    {
        cout << "Rectangle";
        // return "Rectangle";
    }
};

class Circle : public Shape
{
private:
    double rad;
public:
    Circle(double r) : rad(r)
    {
        // cout << getClassName() << "'s area is " << getArea() << endl;
    }
    void getArea()
    {
        cout << pi * pow(rad, 2) << endl;
    }
    void getClassName()
    {
        cout << "Circle";
        // return "Circle";
    }
};

class Square : public Shape
{
private:
    double side;
public:
    Square(double s) : side(s) 
    {
        // cout << getClassName() << "'s area is " << getArea() << endl;
    }
    void getArea()
    {
        cout << side * side << endl;
    }
    void getClassName()
    {
        cout << "Square";
        // return "Square";
    }
};




class ShapeGroupID : public Shape 
{
protected:
    vector<Shape*> elems;
    vector<int> IDs;
public:
    ShapeGroupID() 
    {
        // cout << "ShapeGroupID::Copy Constructor" << endl;
    }
    void getArea() 
    {
        // input your code here
        for (size_t i = 0; i < elems.size(); i++)
        {
            elems[i]->getClassName();
            cout << " of id " << IDs[i] << "'s area:" << endl;
            elems[i]->getArea();
        }
    }
    int index = 0;
    void getClassName() 
    {
        for (size_t i = 0; i < elems.size(); i++)
        {
            elems[i]->getClassName();
        }
    }
    
    void insert(Shape* s) 
    {
        elems.push_back(s);
        IDs.push_back(rand() % 100);
    }
    void insert(ShapeGroupID& sgid) 
    {
        // input your code here
        for (size_t i = 0; i < sgid.elems.size(); i++)
        {
            elems.push_back(sgid.elems[i]);
            IDs.push_back(sgid.IDs[i]);
        }
    }
    // copy constructor
    ShapeGroupID(const ShapeGroupID& rhs) 
    {
        // input your code here
        cout << "ShapeGroupID::Copy Constructor" << endl;
        for (size_t i = 0; i < rhs.elems.size(); i++)
        {
            elems.push_back(rhs.elems[i]);
            IDs.push_back(rhs.IDs[i]);
        }
    }
    // destructor
    ~ShapeGroupID()
    {
        cout << "ShapeGroupID::Destructor" << endl;
    }
};



int main() {
srand(420);
ShapeGroupID sgID;
Rectangle* r1 = new Rectangle(10, 20);
Circle* c1 = new Circle(10);
Square* s1 = new Square(10);
sgID.insert(r1);
sgID.insert(c1);
sgID.insert(s1);
ShapeGroupID sgID2;
Circle* c2 = new Circle(5);
Square* s2 = new Square(5);
sgID2.insert(c2);
sgID2.insert(s2);
ShapeGroupID sgID3(sgID);
Circle* c3 = new Circle(20);
Square* s3 = new Square(20);
sgID3.insert(c3);
sgID3.insert(s3);
sgID3.insert(sgID2);
sgID3.getArea();
delete r1, c1, s1, c2, s2, c3, s3;
}