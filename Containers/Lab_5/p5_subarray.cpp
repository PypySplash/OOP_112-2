#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

bool findSubarrayWithZeroSum(const vector<int>& nums) 
{
    unordered_set<int> sumSet;
    int sum = 0;
    for (int num : nums) {
        sum += num;
        // 檢查當前總和是否為0或已經存在於集合中
        // 若 find(sum) 沒找到東西，會回傳 sumSet.end()，就是集合末尾的迭代器，表示搜尋未成功找到該元素
        if (sum == 0 || sumSet.find(sum) != sumSet.end())  // ex. [1, 2, -3, 3, 4]，從左至右遍歷總和，前兩項和為 3，前四項和也為 3，表示這兩次的中間和會為 0，否則不可能會回到一樣的數。
        {
            return true; // 找到了和為0的子數組
        }
        sumSet.insert(sum);
    }
    return false; // 沒有找到和為0的子數組
}

int main() 
{
    int numInArray;
    cout << "How many number in the array?" << endl;
    cin >> numInArray;

    cout << "Input the array" << endl;
    vector<int> nums;
    for (int i = 0; i < numInArray; i++)
    {
        int n;
        cin >> n;
        nums.push_back(n);
    }

    if (findSubarrayWithZeroSum(nums)) 
    {
        cout << "Found a subarray with 0 sum" << endl;
    } 
    else 
    {
        cout << "No Such Sub Array Exists!";
    }
    return 0;
}
