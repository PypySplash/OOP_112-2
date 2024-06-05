#ifndef STUDENT_H
#define STUDENT_H
#include <memory>
#include <iostream>
#include <string>

using namespace std;

// 前置聲明
class Class;

class Student
{
private:
    string name;
    weak_ptr<Class> classPtr;

public:
    Student(const string& n);
    void setClass(const shared_ptr<Class>& c);
    string getName() const;
    string getClassName() const;
    ~Student();
};

#endif
