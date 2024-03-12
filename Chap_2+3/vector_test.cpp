#include <iostream>
#include <vector>
using namespace std;
int main ()
{
 vector<int> i(10);
 cout << i.capacity() << endl;

 i.push_back(7);
 cout << i.capacity() << endl;

 vector<int> j;
 cout << j.capacity() << endl;
 j.push_back(7);
 cout << j.capacity() << endl;
 j.push_back(7);
  cout << j.capacity() << endl;
 j.push_back(7);
 cout << j.capacity() << endl;
 j.push_back(7);
 cout << j.capacity() << endl;
 j.push_back(7);
 cout << j.capacity() << endl;
}