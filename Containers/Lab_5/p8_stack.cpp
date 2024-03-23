#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void printPrevSmaller(vector<int>& arr) 
{
    stack<int> s;
    vector<int> prevSmaller(arr.size());

    // 遍歷每個元素
    for (int i = 0; i < arr.size(); ++i) 
    {
        // 當棧不為空，且棧頂元素大於或等於當前元素時，彈出棧頂元素
        while (!s.empty() && arr[s.top()] >= arr[i]) 
        {
            s.pop();
        }

        // 如果棧為空，則當前元素左邊沒有更小的元素，賦值為-1
        // 否則棧頂元素就是當前元素左邊最近的更小元素
        prevSmaller[i] = s.empty() ? -1 : arr[s.top()];

        // 將當前元素索引入棧
        s.push(i);
    }

    // 輸出結果
    for (int i = 0; i < arr.size(); ++i) 
    {
        cout << prevSmaller[i] << " ";
    }
    cout << endl;
}

int main() 
{
    cout << "Please input array, end with 'q' "<< endl;
    int integer;
    vector<int> arr;
    while (cin >> integer)
    {
        arr.push_back(integer);
    }

    printPrevSmaller(arr);
    return 0;
}
