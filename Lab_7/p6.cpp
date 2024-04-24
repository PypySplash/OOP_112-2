#include <iostream>
#include <memory>
using namespace std;



class Person
{
private:
    string name;
public:
    Person(const string& n) : name(n) {}
    void introduce() const
    {
        cout << "Hi, my name is " << name << endl;
    }
};

unique_ptr<Person> createPerson(const string& name)
{
    return unique_ptr<Person>(new Person(name));  // 使用 make_unique 來建立 unique_ptr
}


int main() 
{
    unique_ptr<Person> p = createPerson("Albert");
    p->introduce();
    return 0;
}
