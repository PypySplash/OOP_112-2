#include <iostream>
using namespace std;



class Rectangle 
{
private:
    int width;
    int height;
public:
    Rectangle() : width(0), height(0) {}
    Rectangle(int w, int h) 
    {
        width = w;
        height = h;
    }
    int area() {return width * height;}
    int perimeter() {return 2 * (width + height);}
};



int main() {
// creates a Rectangle object with width and height initialized to 0
Rectangle rect1;
// creates a Rectangle object with width 5 and height 10
Rectangle rect2(5, 10);
cout << "area1: " << rect1.area() << endl;
cout << "area2: " << rect2.area() << endl;
cout << "perimeter1: " << rect1.perimeter() << endl;
cout << "perimeter2: " << rect2.perimeter() << endl;
}