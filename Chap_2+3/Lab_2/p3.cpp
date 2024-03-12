#include <iostream>
using namespace std;

struct Rectangle
{
    int length;
    int width;
};

int main()
{
    Rectangle r;

    int a = 0, b = 0;
    cout << "Enter the length: " << endl;
    cin >> a;
    r.length = a;

    cout << "Enter the width: " << endl;
    cin >> b;
    r.width = b;

    cout << "Area: " << r.length * r.width << endl;
    cout << "Perimeter: " << 2* (r.length + r.width) << endl;
}
