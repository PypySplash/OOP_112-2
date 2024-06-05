#include <iostream>
#include <string>
using namespace std;



class Student
{
private:
public:
    Student(string n, string id, string m) : name(n), id(id), major(m) {}
    string name;
    string id;
    string major;
};



ostream& print(ostream& os, const Student& s) 
{
    os << "Name: " << s.name << endl
       << "ID: " << s.id << endl
       << "Major: " << s.major << endl;
    return os;
}



int main() {
Student a = Student("Mujay", "R10521517", "CE");
print(cout, a);
}