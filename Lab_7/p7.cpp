#include <iostream>
using namespace std;


int call_count() 
{
    // Please fill this blank
    // static 只會初始化一次，並且值不會在函數調用完畢後消失，會保持到下次函數調用。
    static int count = 0;
    count++;
    return count;
}



int main() 
{
    cout << "Call count: " << call_count() << endl;
    cout << "Call count: " << call_count() << endl;
    cout << "Call count: " << call_count() << endl;
    cout << "Call count: " << call_count() << endl;
    return 0;
}