#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int firstUniqChar(string s) {
    unordered_map<char, int> charCount;
    // 統計每個字符出現的次數
    for (char c : s) {
        charCount[c]++;
    }
    // 找出第一個只出現一次的字符
    for (int i = 0; i < s.length(); i++) {
        if (charCount[s[i]] == 1) {
            return i; // 返回這個字符的索引
        }
    }
    return -1; // 如果沒有找到，返回-1
}

int main() {
    string input;
    cin >> input;

    int index = firstUniqChar(input);
    if (index != -1)
    {
        cout << "index: " << index << endl;
    }
    else
    {
        cout << "No unique character found." << endl;
    }
    return 0;
}
/*
Given string: oopalbertlecturenice
2
Given string: oopoopalbertalbert
No unique character found.
*/