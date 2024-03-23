#include <iostream>
#include <unordered_map>
using namespace std;

int main() 
{
    unordered_map<string, int> umap;

    // 使用 insert 方法添加鍵值對
    umap.insert(make_pair("C++", 0));
    umap.insert(make_pair("NTU", 100));
    
    umap["OOP"] = 10;
    umap["Practice"] = 20;
    for (const auto& x : umap)
    cout << x.first << " " << x.second << endl;
}