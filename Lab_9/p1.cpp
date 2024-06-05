#include <iostream>
using namespace std;



class Student
{
    int ID;
    string sName;
    // create constructor
public:
    Student(const string& _sName) : sName(_sName) {}
    Student() = default;
};
int main(){
Student s1;
Student s2(s1);
}