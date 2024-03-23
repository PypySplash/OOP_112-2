#include <iostream>
using namespace std;

bool isPowerOfThree(int n)
{
    if (n == 1) return true;
    else if (n < 1 || n % 3 != 0) return false;
    return isPowerOfThree(n / 3);
}

int main()
{
    int num;
    cout << "Input: n = ";
    cin >> num;
    cout << boolalpha << "Output: " << isPowerOfThree(num) << endl;
}