#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() 
{
    vector<int> nums, results;
    deque<int> q; // 用來存儲窗口中所有有潛力成為最大值的元素的索引
    int k, n, a;
    cin >> n; // 讀取數組大小
    cin >> k; // 讀取窗口大小
    for (int i = 0; i < n; i++) 
    {
        cin >> a; // 讀取數組元素
        nums.push_back(a);
    }
    for (int i = 0; i < nums.size(); i++) 
    {
        // 移除所有小於當前元素的值，因為它們不可能是這個窗口的最大值
        while (q.size() > 0 && nums[q.back()] < nums[i]) 
        {
            // Please fill this blank
            q.pop_back();
        }
        // Please fill this blank
        q.push_back(i); // 將當前元素索引加入到deque中

        // 如果deque的前面的元素已經不在窗口範圍內，則將其移除
        if (q.front() <= i - k) 
        {
            // Please fill this blank
            q.pop_front();
        }

        // 從第k-1個元素開始，每次迭代都將當前窗口的最大值加入到結果中
        if (i >= k - 1) 
        {
            // Please fill this blank
            results.push_back(nums[q.front()]);
        }
    }

    for (auto &p : results) 
    {
        cout << p << " ";
    }

    return 0;
}
