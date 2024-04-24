#include <iostream>
using namespace std;


class OOPClass
{
private:
    static int count;
public:
    // 構造函數
    OOPClass() 
    {
        count++;
        cout << "Instance of OOPClass created" << endl;
    }
    void static printCount()
    {
        cout << "Instance of OOPClass: " << count << endl;
    }
};

// 初始化靜態成員變數
int OOPClass::count = 0;

int main() 
{
    OOPClass a1;
    OOPClass a2;
    OOPClass a3;
    OOPClass::printCount();
    OOPClass a4;
    OOPClass a5;
    OOPClass::printCount();
}
