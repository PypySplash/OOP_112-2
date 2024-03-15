#include <iostream>
using namespace std;

int gcd(int v1, int v2);
int lcm(int v1, int v2);

int main()
{
    int num1, num2;
    cout << "Input: (a, b): ";
    cin >> num1 >> num2;
    cout << "Output: " << lcm(num1, num2) << endl;
}

int gcd(int v1, int v2)
{
    if (v2 == 0) return v1;
    else return gcd(v2, v1 % v2);
}

int lcm(int v1, int v2)
{
    return (v1 / gcd(v1, v2)) * v2; 
}
