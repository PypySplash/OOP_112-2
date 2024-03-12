#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Please give an integer: " << endl;
    cin >> n;
    int ans = 1;
    if (n >= 0)
    {
        for (int i = 0; i < n; i++) 
        {
            ans *= i + 1;
        }
        cout << ans << endl;
    }
    if (n < 0)
        cout << "Input should be non negative integer" << endl;
}