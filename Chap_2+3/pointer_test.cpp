#include <iostream>
using namespace std;

int main()
{
    string* pstring;
    int* i;
    string s("hello world");
    string *sp = &s;
    cout << *sp;

    int ival = 1024;
    int* pi = &ival;
    int** ppi = &pi;
    cout << "The value of ival" << endl
 << "direct value: " << ival << endl
 << "indirect value: " << *pi << endl
 << "doubly indirect value: " << **ppi << endl << endl;

cout << "raw pi: " << pi << endl
 << "dereferenced pi: " << *pi << endl
 << "raw ppi: " << ppi << endl
 << "dereferenced ppi: " << *ppi << endl;
}