#include <iostream>
#include <cmath>
#include <unordered_map>
#include <vector>
using namespace std;

int findLuckyInt(vector<int>& arr);

int main()
{
    cout << "Input: " << endl;
    cout << "n: ";
    int n;
    cin >> n;
    cout << "arr: ";
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        cin >> temp;
        arr.push_back(temp);
    }
    cout << "Output: " << findLuckyInt(arr) << endl;
}

int findLuckyInt(vector<int>& arr)
{
    unordered_map<int, int> intFreqMap;
    for (int num : arr)
    {
        intFreqMap[num]++;
    }
    int luckyInteger = -1;
    for (auto& [num, freq] : intFreqMap)
    {
        if (num == freq && num > luckyInteger)
        {
            luckyInteger = num;
        }
    }
    return luckyInteger;
}
