#include <iostream>
using namespace std;

int sumUpToN(int N);

int main()
{
    cout << "Input: " << endl;
    cout << "n: ";
    int n;
    cin >> n;
    cout << "Output: " << sumUpToN(n) << endl;
}

int sumUpToN(int N)
{
    if (N == 0) return 0;
    else
    {
        return N + sumUpToN(N - 1);
    }
}