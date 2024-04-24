#include <iostream>
using namespace std;



class Square
{
private:
    int side;
public:
    Square(int s) : side(s) {}
    friend class Rectangle;
};



class Rectangle
{
private:
    int width;
    int height;
public:
    int area() {return width * height;}
    void convert(Square sq) 
    {
        width = sq.side;
        height = sq.side;
    }
    void print()
    {
        cout << "width: " << width << ", height: " << height << ", area: " << width * height << endl;
    }
};



int main () {
cout << "input: ";
int side;
cin >> side;
Rectangle rect;
Square sqr(side);
rect.convert(sqr);
rect.print();
return 0;
}