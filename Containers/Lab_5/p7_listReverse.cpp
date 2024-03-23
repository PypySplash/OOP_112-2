#include <iostream>
#include <list>
#include <iterator>

using namespace std;

// 函數來反轉列表中從 start 到 end 範圍的元素
// 注意：這裡的 start 和 end 是以 0 為基的索引
void reverseListPortion(list<int> &lst, int start, int end) 
{
    if (start >= end || lst.empty()) return; // 無效範圍或空列表

    list<int>::iterator startIt = lst.begin();
    advance(startIt, start);  // 將迭代器移動到列表中 start 指定的位置

    list<int>::iterator endIt = lst.begin();
    advance(endIt, end);  // 將迭代器移動到列表中 end 指定的位置

    while (start < end) {
        iter_swap(startIt, endIt);
        if (startIt != lst.end()) ++startIt;
        if (endIt != lst.begin()) --endIt;
        ++start;
        --end;
    }
}

int main() 
{
    int m, n;
    cout << "Where to reverse the list? from m to n" << endl;
    cin >> m >> n;

    cout << "Input your list, end with 'q' " << endl;
    int integer;
    list<int> myList;
    while (cin >> integer)
    {
        myList.push_back(integer);
    }

    // 反轉列表中第 m 到第 n 元素的位置
    reverseListPortion(myList, m - 1, n - 1);  // 注意：索引從 0 開始

    cout << "After reverse" << endl;
    for (int num : myList) 
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
