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
    if(start != string::npos)  // 表示找不到返回值時。在這個例子就是找到第 1 個不為 0 的數
        number = number.substr(start);

    cout << number;
}
