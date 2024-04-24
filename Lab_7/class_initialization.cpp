// effects of value initilization
// https://en.cppreference.com/w/cpp/language/value_initialization
// 2) if T is a class type with a default constructor that is not user-declared (until C++11)
// neither user-provided nor deleted (since C++11) (that is, it may be a class with 
// an implicitly-defined or defaulted default constructor), the object is zero-initialized 
// and the semantic constraints for default-initialization are checked, and if T has a 
// non-trivial default constructor, the object is default-initialized;

#include <iostream>

class A 
{
public:
  int a;
};

using namespace std;

void m() 
{
  A* obj = new A; // default initialized
  cout << "garbage: " << obj->a << endl;
  delete obj;
}

void m2() 
{
  A* obj = new A{}; // value initialized
  cout << "Not garbage: " << obj->a << endl;
  delete obj;
}

int main()
{
    m();
    m();
    m();
    m2();
    m2();
    m2();

    return 0;
}