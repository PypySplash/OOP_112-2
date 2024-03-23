#include <iostream>
#include <cmath>
using namespace std;

void overload();
void overload(int);
void overload(string s);

int main() {
    overload();
    int i = 2;
    overload(i);
    string s = "abcde";
    overload(s);
    overload("fghij");
}

void overload()
{
    cout << "no arg version!" << endl;
}
void overload(int)
{
    cout << "overload: i++ = 3" << endl;
}
void overload(string s)
{
    cout << "overload(s): " << s << endl;
}
