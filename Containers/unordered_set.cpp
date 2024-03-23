#include <iostream>
#include <unordered_set>
using namespace std;

struct Hasher 
{
    size_t operator() (const pair<int, int>& x) const 
    {
        return x.first ^ x.second; // bitwise xor
    }
};

int main() 
{
    unordered_set<pair<int, int>, Hasher> us;
    us.insert({5, 2});
    us.insert({6, 1});
    us.insert({1, 7});
    us.insert({4, 9});
    us.insert({0, 6});
    for (const auto& x : us) {
    cout << x.first << " " << x.second;
    cout << " Hash value: " << us.hash_function()(x) << endl;
    }
    cout << us.bucket_size(6) << std::endl;
}
