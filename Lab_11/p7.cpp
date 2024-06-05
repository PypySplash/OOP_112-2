#include <iostream>
using namespace std;
#include <vector>



class Shark
{
private:
    int age;
public:
    Shark(int a) : age(a) 
    {
        cout << "New Shark with age: " << age << endl;
    }
    virtual string getClassName()
    {
        return "Shark";
    }
    virtual void print(ostream& cout) 
    {
        cout << "Age " << age << " Shark~~ BOO!BOO!BOO!" << endl;
    }
    virtual void dance()
    {
        cout << "This is Shark dancing!!!!" << endl;
    }
    friend ostream& operator<<(ostream& cout, Shark& shark)
    {
        shark.print(cout);
        return cout;
    }
    ~Shark() 
    {
        cout << "Age " << age << " " << getClassName() << "~~ Bye!" << endl;
    }
};

class BabyShark : public Shark
{
private:
    int babyage;
public:
    BabyShark(int a) : Shark(a) 
    {
        babyage = a;
        cout << "New BabyShark with age: " << a << endl;
    }
    string getClassName() override
    {
        return "BabyShark";
    }
    void dance() override
    {
        cout << "This is BabyShark dancing!!!!" << endl;
    }
    void print(ostream& cout) override
    {
        Shark::print(cout);
        cout << "Age " << babyage << " BabyShark~~ DOO!DOO!DOO!" << endl;
    }
    ~BabyShark()
    {
        cout << "Age " << babyage << " BabyShark~~ Bye!" << endl;
    }
};



int main() {
cout << "---------a-----------" << endl;
Shark shark0(35);
BabyShark shark1(20);
BabyShark shark2(6);
vector<Shark*> vec;
vec.push_back(&shark0);
vec.push_back(&shark1);
vec.push_back(&shark2);
cout << "---------b-----------" << endl;
for(auto& i : vec)
i->dance();
cout << "---------c-----------" << endl;
}