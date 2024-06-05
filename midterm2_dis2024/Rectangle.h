#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>

class Rectangle
{
private:
    std::string color;
    double length;
    double width;
public:
    Rectangle() : color("White"), length(1), width(1) {}
    Rectangle(double l, double w) : color("White"), length(l), width(w) {}
    Rectangle(std::string c, double l, double w) : color(c), length(l), width(w) {}
    // copy constructor
    Rectangle(const Rectangle& other) : color(other.color), length(other.length), width(other.width) {}
    // assignment operator
    Rectangle& operator=(const Rectangle& other) 
    {
        if (this != &other)
        {
            color = other.color;
            length = other.length;
            width = other.width;
        }
        return *this;
    }
    void changeColor(std::string c) 
    {
        color = c;
    }
    void changeWidth(double w)
    {
        width = w;
    }
    void changeLength(double l)
    {
        length = l;
    }
    int isSquare()
    {
        if (length == width) return 1;
        else return 0;
    }
    friend std::ostream& operator<<(std::ostream& cout, const Rectangle& rec)
    {
        cout << "Color: " << rec.color << ", Length: " << rec.length << ", Width: " << rec.width;
        return cout;
    }
};



#endif