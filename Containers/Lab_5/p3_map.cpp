#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, int> nameCounts;
    int n;
    string name;

    cout << "How many names?" << endl;
    cin >> n;
    cin.ignore(); // 忽略換行符號，避免影響後續的getline

    for (int i = 0; i < n; ++i) {
        // 輸入完名字按下 Enter 來換行繼續輸入名字，這樣較符合邏輯，避免有人的名字中會有空格
        getline(cin, name);
        ++nameCounts[name];
    }

    for (const auto& pair : nameCounts) 
    {
        cout << "Name: " << pair.first << ", Value: " << pair.second << endl;
    }

    return 0;
}
