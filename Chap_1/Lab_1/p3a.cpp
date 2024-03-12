#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Please give an integer: " << endl;
    cin >> n;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count = i + 1;
        while (count > 0)
        {
            cout << i + 1;
            count--;
        }
        cout << endl;
    }
}