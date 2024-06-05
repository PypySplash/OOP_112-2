#include <iostream>
using namespace std;

const int MAX_CAPACITY = 100;

int main()
{
    int* intArray = new int [MAX_CAPACITY];
    int integers;
    int count = 0;

    while (count < MAX_CAPACITY)
    {
        cin >> integers;
        if (integers < 0) break;
        intArray[count] = integers;
        count++;
    }

    int sum = 0;
    for (int i = 0; i < count; i++) sum += intArray[i];

    cout << sum << endl;

    delete [] intArray;
}
