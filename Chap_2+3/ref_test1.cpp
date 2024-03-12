#include <iostream>
using namespace std;

int main()
{
    int i = 5;
    int& j = i; // j is an alternative name to i
    int k = i;

    cout << "Before i change, i = " << i << endl;
    cout << "Before i change, j = " << j << endl;
    cout << "Before i change, k = " << k << endl;
    i = 6;
    cout << "After i change: i = " << i << endl;
    cout << "After i change: j = " << j << endl;
    cout << "After i change: k = " << k << endl;
}