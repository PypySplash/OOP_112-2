#include <iostream>
#include <unordered_map>
using namespace std;
struct Hasher {
// We use predefined hash functions of strings and
// define our hash function as XOR of the hash values.
size_t operator()(const pair<string, string> &s) const {
return (hash<string>()(s.first)) ^
(hash<string>()(s.second)); // bitwise xor
}
};
int main() {
unordered_map< pair<string, string>, string, Hasher> us;
us.insert({{"C++", "OOP"}, "Great"});
us.insert({{"NTU", "CE"}, "Wonderful"});
for (const auto& x : us) {
cout << x.first.first << " " << x.first.second << " is " <<
x.second;
cout << ", Hash value: " << us.hash_function()(x.first) <<
endl;
}
}