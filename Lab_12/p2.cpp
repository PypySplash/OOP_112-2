#include <iostream>
using namespace std;



class Shark
{
protected:
    int* age;
public:
    Shark() : age(nullptr) {}
    Shark(int a) : age(new int(a)) 
    {
        cout << "New Shark with age: " << a << endl;
    }
    virtual void print(ostream& out) 
    {
        cout << "Age " << *age << " Shark~~ BOO!BOO!BOO!" << endl;
    }
    // copy constructor
    Shark(const Shark& other)
    {
        age = new int(*other.age);
        cout << "Copy Shark with age: " << *age << endl;
    }
    // Copy Assignment operator
    Shark& operator=(const Shark& other)
    {
        if (this != &other)
        {
            delete age;
            age = new int(*(other.age));
            cout << "Copy assign Shark with age: " << *age << endl;
        }
        return *this;
    }
    virtual ~Shark() 
    {
        cout << "Age " << *age << " Shark~~ Bye!" << endl;
        delete age;
    }
};



class BabyShark : public Shark
{
public:
    BabyShark() = default;
    BabyShark(int a) : Shark(a) 
    {
        cout << "New BabyShark with age: " << a << endl;
    }
    void print(ostream& out) override
    {
        Shark::print(out);
        cout << "Age " << *age << " BabyShark~~ DOO!DOO!DOO!" << endl;
    }
    // copy constructor
    BabyShark(const BabyShark& other) : Shark(other)
    {
        cout << "Copy BabyShark with age: " << *age << endl;
    }
    // Copy Assignment operator
    BabyShark& operator=(const BabyShark& other)
    {
        if (this != &other)
        {
            Shark::operator=(other);
            cout << "Copy assign BabyShark with age:" << *age << endl;
        }
        return *this;
    }
    ~BabyShark() override
    {
        cout << "Age " << *age << " BabyShark~~ Bye!" << endl;
    }
};



ostream& operator << (ostream& out, Shark& s) {
s.print(out);
return out;
}
int main() {
BabyShark shark1(20);
cout << "-----------------------" << endl;
Shark* shark2 = new BabyShark(shark1);
cout << "-----------------------" << endl;
BabyShark shark3;
shark3 = shark1;
cout << "-----------------------" << endl;
cout << shark1 << *shark2 << shark3;
cout << "-----------------------" << endl;
delete shark2;
return 0;
}