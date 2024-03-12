#include <iostream>
using namespace std;

int main() 
{
    int n;
    cout << "請輸入數字n: ";
    cin >> n;

    for(int i = 1; i <= n; ++i) 
    {
        // 計算並列印底線的數量
        for(int j = 1; j <= n - i; ++j) 
            cout << "_";

        // 計算並列印星號的數量
        for(int j = 1; j <= 2 * i - 1; ++j)
            cout << "*";

        // 列印星號後面對應的底線數量
        for(int j = 1; j <= n - i; ++j)
            cout << "_";

        cout << endl;
    }

    return 0;
}
