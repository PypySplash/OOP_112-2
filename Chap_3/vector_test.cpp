#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(1);
v.push_back(2);
v.push_back(3);
v.push_back(4);

    v.at(3) = 7;
    cout << "position 3: " << v.at(3) << endl;

    v[2] = 8;
    cout << "position 2: " << v[2] << endl;

    v.push_back(5);

    cout << "size of vector: " << v.size() << endl;
    cout << "capacity of vector: " << v.capacity() << endl;
    cout << "position 6: " << v[6] << endl; // bad but allowed
    cout << "position 6: " << v.at(6) << endl; // try this
    cout << "position 10: " << v[10] << endl; //bad but allowed
}
