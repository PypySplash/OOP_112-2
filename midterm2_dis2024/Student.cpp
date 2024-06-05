#include "Student.h"
#include "Class.h"

Student::Student(const string& n) : name(n) {}

void Student::setClass(const shared_ptr<Class>& c) {
    classPtr = c;
    // auto lockedClass = classPtr.lock();
    // if (lockedClass) {
    //     cout << name << " is in: " << lockedClass->getName() << endl;
    // } else {
    //     cout << "Class no longer exists." << endl;
    // }
}

string Student::getName() const {
    return name;
}

string Student::getClassName() const {
    auto lockedClass = classPtr.lock();
    return lockedClass ? lockedClass->getName() : "No class";
}

Student::~Student() {
    cout << "Student destructor: " << name << endl;
}
