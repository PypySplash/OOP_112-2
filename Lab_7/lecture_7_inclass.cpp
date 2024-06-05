#include <memory>
#include <iostream>
using namespace std;


void m(shared_ptr<int>& a) 
{
    cout << "2: " << a.use_count() << endl;  // 2: 1
    shared_ptr<int> b(a);
    cout << "3: " << a.use_count() << endl;  // 3: 2
    return;
}

int main() 
{
    shared_ptr<int> j;
    {
        shared_ptr<int> i;
        i = make_shared<int>(5);
        cout << "1: " << i.use_count() << endl;  // 1: 1
        m(i);
        cout << "4: " << i.use_count() << endl;  // 4: 1
        j = i;
        cout << "5: " << i.use_count() << endl;  // 5: 2
    }
    cout << "6: " << j.use_count() << endl;  // 6: 1
    j = nullptr; // destroy object pointed by shared_ptr j
    cout << "7: " << j.use_count() << endl;  // 7: 0
}