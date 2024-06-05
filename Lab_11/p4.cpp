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
    virtual void print() 
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
protected:
    int getNumer() const { return numer; }
    int getDenom() const { return denom; }
    void setNumer(int n) { numer = n; }
    void setDenom(int d) { denom = d; }
};



class RFraction : public Fraction
{
public:
    RFraction() = default;
    RFraction(int n, int d) : Fraction(n, d) {}
    int gcd(int a, int b)
    {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    void reduce()
    {
        int divisor = gcd(getNumer(), getDenom());
        setNumer(getNumer() / divisor);
        setDenom(getDenom() / divisor);
    }
    void print() override
    {
        reduce();
        cout << getNumer() << "/" << getDenom();
    }
};



int main() {
RFraction rf1(2, 4);
RFraction rf2;
cin >> rf2;
cout << "Reduced fractions are: ";
cout << rf1 << ", ";
cout << rf2 << endl;
return 0;
}