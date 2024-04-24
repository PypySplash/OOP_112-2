#include <iostream>
using namespace std;

const int MAX_CAPACITY = 100;

int main()
{
    int* integers = new int [MAX_CAPACITY];
    int input;
    int count = 0;

    while (count < MAX_CAPACITY)
    {
        cin >> input;
        if (input < 0) break;
        integers[count] = input;
        count++;
    }

    int sum = 0;
    for (int i = 0; i < count; i++) sum += integers[i];

    cout << sum << endl;

    delete [] integers;
}
