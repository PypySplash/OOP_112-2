#ifndef CLASS_H
#define CLASS_H
#include <iostream>
#include <vector>
#include "Student.h"

using namespace std;
class Student;

class Class
{
private:
    string name;
    vector<shared_ptr<Student> > sp_vector;
public:
    Class(const string& n) : name(n) {}
    void registerStudent(const shared_ptr<Student>& s)
    {
        sp_vector.push_back(s);
    }
    string getName() const {return name;}
    void printStudents() 
    {
        cout << "Students in " << name << ":" << endl;
        for (int i = 0; i < sp_vector.size(); i++)
        {
            cout << sp_vector[i]->getName() << endl;
        }
    }
    ~Class() 
    {
        cout << "Class destructor: " << name << endl;
    }
};

#endif