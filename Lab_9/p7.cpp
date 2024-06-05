#include <iostream>
using namespace std;



class Complex
{
private:
    int real;
    int imag;
public:
    Complex() = default;
    Complex& operator+(const Complex& other)
    {
        real += other.real;
        imag += other.imag;
        return *this;
    }
    friend istream& operator>>(istream& cin, Complex& complex) 
    {
        cin >> complex.real >> complex.imag;
        return cin;
    }
    friend ostream& operator<<(ostream& cout, const Complex& complex)
    {
        cout << complex.real << "+" << complex.imag << "i";
        return cout;
    }
    bool operator>=(const Complex& other) const
    {
        return real > other.real;
    }
};
int main() {
Complex c1, c2;
cin >> c1 >> c2;
if(c1 >= c2)
cout << c1 << " >= " << c2 << endl;
else
cout << c1 << " < " << c2 << endl;
return 0;
}
