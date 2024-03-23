#include <algorithm>
#include <iostream>
#include <list>
using namespace std;

int main(){
    list<int> l;
    l.push_back(17);
    l.push_back(55);
    l.push_back(16);
    l.push_back(3);
    // 此時 l 中的元素會是 {17, 55, 16, 3}
    //cout << l[3]; // cannot do this!
    // Insert an integer before 16 by searching
    auto it = find(l.begin(), l.end(), 16); // it points at 16
    if (it != l.end()){
    l.insert(it, 77); // constant time insert
    // list is now 17, 55, 77, 16, 3
    }
    it--; // move it to 77
    it--; // move it to 55
    l.erase(it); // constant time erase
    for (const auto &ele : l)
    cout << ele << ' ';
    cout << std::endl;
}