#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void simulateCardSequence(int n) 
{
    queue<int> cards;
    vector<int> discarded;

    // 初始化 Queue，放入1到n的卡牌
    for (int i = 1; i <= n; ++i) 
    {
        cards.push(i);
    }

    // 當隊列中至少有兩張卡牌時執行
    while (cards.size() > 1) {
        // 記錄並移除頂部卡牌
        discarded.push_back(cards.front());
        cards.pop();

        // 將新的頂部卡牌移動到隊列尾端
        cards.push(cards.front());
        cards.pop();
    }

    // 輸出被丟棄的卡牌序列
    cout << "Discarded cards:";
    if (!discarded.empty()) {
        for (size_t i = 0; i < discarded.size(); ++i) {
            cout << " " << discarded[i];
        }
    } else {
        cout << " None";
    }
    cout << endl;

    // 輸出最後剩餘的卡牌
    cout << "Remaining card: " << cards.front() << endl;
}

int main() {
    int n;
    cout << "How many cards?" << endl;
    cin >> n;
    simulateCardSequence(n);
    return 0;
}
