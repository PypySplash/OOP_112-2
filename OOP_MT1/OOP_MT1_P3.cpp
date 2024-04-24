#include <iostream>
#include <vector>
#include <map>
#include <deque>
#include <string>
#include <queue>
#include <stack>

using namespace std;

struct Person
{
    string name;
    int age;
};

int main() {
    deque<Person> dq;
    string name;
    int age;

    while (true) {
        cin >> name;
        if (name == "exit!") break;

        if (!(cin >> age)) 
        {
            // 處理無效的年齡輸入
            cin.clear(); // 清除錯誤標誌
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略錯誤輸入直到下一行
            cerr << "Invalid age input. Please enter a valid name and age." << endl;
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 讀取年齡後跳過換行符

        Person p;
        p.name = name;
        p.age = age;

        // 根據當前deque的大小決定插入位置
        if (dq.size() % 2 == 0) {
            dq.insert(dq.begin() + dq.size() / 2, p);
        } else {
            dq.insert(dq.begin() + dq.size() / 2, p);
        }
    }

    // 輸出所有人員信息
    for (const auto& person : dq) {
        cout << person.name << " " << person.age << endl;
    }

    return 0;
}
/*
Input No.1:
Albert 28
David 55
Patrick 60
exit!
*/
/*
Input 2:
Albert 28
James 50
Rex 44
YT 44
exit!
*/

