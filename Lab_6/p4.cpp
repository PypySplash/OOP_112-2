#include <iostream>
using namespace std;



class Complex
{
private:
    int real;
    int imag;
public:
    Complex(int r, int i) : real(r), imag(i) {}
    void print() {cout << real << " + " << imag << "i" << endl;}
    friend Complex add(const Complex& c1, const Complex& c2);
};



Complex add(const Complex& c1, const Complex& c2)
{
    int real = c1.real + c2.real;
    int imag = c1.imag + c2.imag;
    return Complex(real, imag);
}



int main() {
Complex c1(2, 3);
Complex c2(4, -5);
cout << "c1 = ";
c1.print();
cout << "c2 = ";
c2.print();
Complex c3 = add(c1, c2);
cout << "c1 + c2 = ";
c3.print();
return 0;
}
