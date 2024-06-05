#include <iostream>
using namespace std;



class Employee
{
protected:
    int* age;
    int* salary;
public:
    Employee(int a, int s) 
    {
        age = new int(a);
        salary = new int(s);
        cout << "New Employee: (" << *age << "," << *salary << "k)" << endl;
    }
    ~Employee()
    {
        delete age;
        delete salary;
    }
};

class Engineer : public Employee
{
public:
    Engineer(int a, int s) : Employee(a, s) 
    {
        cout << "New Engineer: (" << *age << "," << *salary << "k)" << endl;
    }
};
class Manager : public Employee
{
public:
    Manager(int a, int s) : Employee(a, s) 
    {
        cout << "New Manager:  (" << *age << "," << *salary << "k)" << endl;
    }
};



int main() {
Engineer e1(24, 40);
Manager m1(27, 50);
return 0;
}



/*
Problem 6.
This is a problem to think about. 
If you have a class with a data member (a shared pointer) 
allocating dynamic memory to be shared among objects when copy construct and copy assignment happen, 
do you need the Rule of 3? 
There is actually the Rule of Zero.

不需要的原因是，當使用了 shared_ptr 這類的智能指標來管理記憶體時，
他本身已經處理了記憶體的分配和釋放，以及對資源的資源的共享控制。
如此稱為 Rule of Zero，優點是可以讓代碼更簡潔安全，
從而減少錯誤發生的可能性，因為資源的管理被委託給這些智能指標。
*/