#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() 
{
    map<int, string> mp ;
    mp.insert(make_pair(7, "I love C++!"));
    mp.insert(make_pair(8, "I love OOP!"));
    mp.insert(make_pair(3, "associative"));
    mp.insert(make_pair(1, "map"));
    mp.insert(make_pair(4, "container"));
    mp.insert(make_pair(2, "is an"));
    mp.insert(make_pair(1, "key")); // another pair with key 1
    for (const auto &ele : mp)
    cout << ele.first << " : " << ele.second << endl;
    if(mp.find(8) != mp.end())
    cout << mp[8] << endl;
    else cout << "no element with key 5" << endl;
    if(mp.find(5) != mp.end())
    cout << mp[5] << endl;
    else cout << "no element with key 5" << endl;
}