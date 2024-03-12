#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string number;
    cin >> number;

    reverse(number.begin(), number.end());

    size_t start = number.find_first_not_of('0');
    if(start != string::npos) 
        number = number.substr(start);

    cout << number;
}