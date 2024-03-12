#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main()
{
    vector<int> vec;
    int input = 0;
    cout << "Enter the elements: " << endl;
    while (cin >> input)
    {
        vec.push_back(input);
    }
    // int max = -10000000000000000;
    // int min = 100000000000000000;
    int max = numeric_limits<int>::min();
    int min = numeric_limits<int>::max();
    for (auto i : vec)
    {
        if (i > max) max = i;
        if (i < min) min = i;
    }
    cout << "Maximum element: " << max << endl;
    cout << "Minimum element: " << min << endl;
}
