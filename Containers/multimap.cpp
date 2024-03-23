#include <iostream>
#include <set>
using namespace std;

struct Cmp {
    bool operator()(const int& lhs, const int& rhs) const {
        return lhs > rhs;
    }
};

// 已經有了 Cmp 結構，所以不再需要定義 Comp 結構

int main() {
    // 由於我們無法使用 auto 和 lambda，我們將直接使用 Cmp 結構來初始化 st1
    set<int, Cmp> st1;
    // 為st1插入元素
    st1.insert(34);
    st1.insert(45);
    st1.insert(1);
    st1.insert(77);
    st1.insert(98);
    st1.insert(15);

    set<int, Cmp> st2;
    // 為st2插入元素
    st2.insert(34);
    st2.insert(45);
    st2.insert(1);
    st2.insert(77);
    st2.insert(98);
    st2.insert(15);

    set<int, greater<int> > st3;
    // 為st3插入元素
    st3.insert(34);
    st3.insert(45);
    st3.insert(1);
    st3.insert(77);
    st3.insert(98);
    st3.insert(15);

    cout << "With custom compare Cmp: ";
    for (const auto& ele : st2)
        cout << ele << ' ';
    cout << endl;
}