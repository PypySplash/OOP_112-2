#include <iostream>
#include <set>
using namespace std;

void printList(const set<int>& st){
for (const auto &ele : st)
cout << ele << ' ';
cout << endl;
}

int main() {
    set<int> st;
    st.insert(9);
    st.insert(3);
    st.insert(12);
    st.insert(2);
    st.insert(10);
    st.insert(4);
    // 此時 st 中的元素會是 {2, 3, 4, 9, 10, 12}，注意元素會自動被排序，且不包含重複
    printList(st);
    st.insert(1);
    st.insert(1); // another 1
    st.insert(6);
    st.insert(11);
    printList(st);
}