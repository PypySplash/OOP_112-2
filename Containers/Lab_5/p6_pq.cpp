#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int connectRopesWithMinCost(vector<int>& ropes) 
{
    // 創建一個最小堆
    priority_queue<int, vector<int>, greater<int> > minHeap(ropes.begin(), ropes.end());
    int totalCost = 0;

    // 當堆中的元素個數大於1時，執行循環（就是每次都取出最上面兩個最小的元素出來
    while (minHeap.size() > 1) {
        // 取出兩個最小的元素
        int first = minHeap.top(); minHeap.pop();
        int second = minHeap.top(); minHeap.pop();
        
        // 計算這兩個元素的和並加到總成本中
        int cost = first + second;
        totalCost += cost;
        
        // 將這兩個元素的和放回最小堆中
        minHeap.push(cost);
    }

    // 返回總成本
    return totalCost;
}

int main() 
{
    cout << "Input your length of every ropes, end with 'q' " << endl;
    int n;
    vector<int> ropes;
    while (cin >> n)
    {
        ropes.push_back(n);
    }

    int cost = connectRopesWithMinCost(ropes);
    
    cout << "The minimum cost is " << cost << endl;
    return 0;
}
