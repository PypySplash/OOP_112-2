#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool canFormPairsWithoutIntersection(const vector<int>& couples) {
    stack<int> s;

    for (int couple : couples) {
        if (!s.empty() && s.top() == couple) 
        {
            // 成功找到配對，移除堆疊頂部元素
            s.pop();
        } 
        else 
        {
            // 尚未找到配對，將當前元素推入堆疊
            s.push(couple);
        }
    }

    // 如果堆疊被清空，表示所有紅繩都成功配對且沒有交叉
    return s.empty();
}

int main() 
{
    int numOfPpl;
    cout << "How many people ?" << endl;
    cin >> numOfPpl;

    vector<int> vec;
    cout << "Please input all the number !" << endl;
    for (int i = 0; i < numOfPpl; i++)
    {
        int num;
        cin >> num;
        vec.push_back(num);
    }
    
    if (canFormPairsWithoutIntersection(vec))
        cout << "excellent!!" << endl;
    else
        cout << "Oh no!!" << endl;
    return 0;
}
