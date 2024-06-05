#include <iostream>
using namespace std;



class Shark
{
protected:
    int age;
public:
    Shark(int a) : age(a) 
    {
        cout << "New Shark with age: " << a << endl;
    }
    virtual void print(ostream& out) 
    {
        cout << "Age " << age << " Shark~~ BOO!BOO!BOO!" << endl;
    }
};



class BabyShark : public Shark
{
public:
    BabyShark(int age) : Shark(age) 
    {
        cout << "New Baby Shark with age: " << age << endl;
    }
    void print(ostream& out) override
    {
        Shark::print(out);
        cout << "Age " << age << " BabyShark~~ DOO!DOO!DOO!" << endl;
    }
};



ostream& operator << (ostream& out, Shark& s) {
s.print(out);
return out;
}
int main() {
BabyShark shark1(20);
cout << "-----------------------" << endl;
cout << shark1;
return 0;
}
