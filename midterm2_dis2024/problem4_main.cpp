#include <vector>
#include <memory>
#include <iostream>

#include "Class.h"
#include "Student.h"

using namespace std;

int main() {
  shared_ptr<Class> mathClass = make_shared<Class>("Math");
  shared_ptr<Class> englishClass = make_shared<Class>("English");

  shared_ptr<Student> alice = make_shared<Student>("Alice");
  shared_ptr<Student> bob = make_shared<Student>("Bob");
  shared_ptr<Student> charlie = make_shared<Student>("Charlie");
  shared_ptr<Student> julian = make_shared<Student>("Julian");

  mathClass->registerStudent(alice);
  alice->setClass(mathClass);
  
  mathClass->registerStudent(bob);
  bob->setClass(mathClass);
  
  englishClass->registerStudent(julian);
  julian->setClass(englishClass);
  
  englishClass->registerStudent(charlie);
  charlie->setClass(englishClass);

  cout << alice->getName() << " is in: " << alice->getClassName() << endl;
  cout << bob->getName() << " is in: " << bob->getClassName() << endl;
  cout << charlie->getName() << " is in: " << charlie->getClassName() << endl;
  cout << julian->getName() << " is in: " << julian->getClassName() << endl;

  mathClass->printStudents();
  englishClass->printStudents();

  return 0;
}
