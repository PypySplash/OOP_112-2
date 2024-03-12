#include <iostream>
using namespace std;

int main()
{
    int i;
    cout << "Please give an integer: " << endl;
    cin >> i;
    if (i % 2 != 0)
        cout << "The value is not divisible by 2." << endl;
    else
        cout << "The value is divisible by 2." << endl;
}