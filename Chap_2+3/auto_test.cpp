#include <iostream>
using namespace std;

int main()
{
    int ival = 1024;
    int *pi = &ival; // pi points to an int
    auto ppi = &pi; // int **ppi

    cout << "val of pi: " << ppi << endl;
    cout << "val of *pi: " << *ppi << endl;
    cout << "val of **pi: " << **ppi << endl;
}