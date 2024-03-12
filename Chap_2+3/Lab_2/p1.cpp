#include <iostream>
using namespace std;

int main()
{
    int num = 10;
    int& refNum = num;
    cout << "Value of refNum: " << refNum << endl;
    int* ptrNum = &num;
    cout << "Value ptrNum is pointing to: " << *ptrNum << endl;
    cout << "Value of ptrNum: " << ptrNum;
}