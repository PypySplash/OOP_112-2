#include <iostream>
using namespace std;



class Fraction
{
private:
    int numer;
    int denom;
public:
    Fraction() = default;
    Fraction(int n, int d) : numer(n), denom(d) {}
    void print() 
    {
        cout << numer << "/" << denom;
    }
    friend istream& operator>>(istream& cin, Fraction& f)
    {
        char slash;
        cin >> f.numer >> slash >> f.denom;
        return cin;
    }
    friend ostream& operator<<(ostream& cout, Fraction& f)
    {
        f.print();
        return cout;
    }
};



int main() {
Fraction f1(2, 4);
Fraction f2;
cin >> f2;
cout << "Fractions are: ";
cout << f1 << ", ";
cout << f2 << endl;
}
