#include <iostream>
using namespace std;



class SafeArray
{
private:
    int intArray[10];
public:
    SafeArray() 
    {
        for (int i = 0; i < 10; i++)
        {
            intArray[i] = i;
        }
    }
    int& operator[] (const int index)
    {
        if (index < 0 || index >= 10)
        {
            cout << "out of range" << endl;
            return intArray[0];
        }
        return intArray[index];
    }
};
int main(){
SafeArray a;
cout << "a[2] = " << a[2] <<endl;
cout << "a[5] = " << a[5]<<endl;
cout << "a[12] = " << a[12]<<endl;
return 0;
}