#include <iostream>
using namespace std;
int main()
{
 int i;
 int& ri = i;
 i = 5;
 ri = 10;
 cout << "i = " << i << endl;
 cout << "ri = " << ri << endl;
 return 0;
}