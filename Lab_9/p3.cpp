#include <iostream>
using namespace std;



class Distance
{
private:
    int feet;
    int inches;
public:
    Distance() = default;
    Distance(int ft, int inch) : feet(ft), inches(inch) {}
    friend istream& operator>>(istream& cin, Distance& D)
    {
        cin >> D.feet >> D.inches;
        return cin;
    }
    friend ostream& operator<<(ostream& cout, const Distance& D) 
    {
        cout << "F : " << D.feet << " I : " << D.inches;
        return cout;
    }


};
int main() {
Distance D1(11, 10), D2(5, 11), D3;
cout << "Enter the value of object : " << endl;
cin >> D3;
cout << "First Distance : " << D1 << endl;
cout << "Second Distance :" << D2 << endl;
cout << "Third Distance :" << D3 << endl;
return 0;
}