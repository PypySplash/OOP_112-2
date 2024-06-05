#include <iostream>
using namespace std;
#include <vector>



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
    // Move Constructor
    Shark(Shark && other) : age(other.age)
    {
        other.age = nullptr;
        cout << "Move construct Shark with age: " << *age << endl;
    }
    // Move assignment operator
    Shark& operator=(Shark&& other)
    {
        if (this != &other)
        {
            delete age;
            age = other.age;
            other.age = nullptr;
            cout << "Move assign Shark with age: " << *age << endl;
        }
        return *this;
    }
    virtual ~Shark() 
    {
        if (age != nullptr) {
            cout << "Age " << *age << " Shark~~ Bye!" << endl;
        } else {
            cout << "Shark with nullptr~~ Bye!" << endl;
        }
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
        out << "Age " << *age << " BabyShark~~ DOO!DOO!DOO!" << endl;
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
    // Move Constructor
    BabyShark(BabyShark && other) : Shark(move(other))
    {
        other.age = nullptr;
        cout << "Move construct BabyShark with age: " << *age << endl;
    }
    // Move assignment operator
    BabyShark& operator=(BabyShark&& other)
    {
        if (this != &other)
        {
            Shark::operator=(move(other));
            cout << "Move assign BabyShark with age: " << *age << endl;
        }
        return *this;
    }
    ~BabyShark() override
    {
        if (age != nullptr) {
            cout << "Age " << *age << " BabyShark~~ Bye!" << endl;
        } else {
            cout << "BabyShark with nullptr~~ Bye!" << endl;
        }
    }
};



ostream& operator << (ostream& out, Shark& s) {
s.print(out);
return out;
}
BabyShark create(int age) {
return BabyShark(age);
}
int main() {
BabyShark shark1(20);
cout << "-----------------------" << endl;
Shark* shark2 = new BabyShark(shark1);
cout << "-----------------------" << endl;
BabyShark shark3;
shark3 = shark1;
cout << "-----------------------" << endl;
vector<BabyShark> vec;
vec.push_back(BabyShark(35));
cout << "-----------------------" << endl;
BabyShark shark4;
shark4 = create(6);
cout << "-----------------------" << endl;
cout << shark1 << *shark2 << shark3 << vec[0] << shark4;
cout << "-----------------------" << endl;
delete shark2;
return 0;
}

/*
Problem 4.
Continuing from the previous problem, briefly explain why we should add “delete shark2” in the main function.
簡單來說，只要有 new 出一塊新的記憶體，就要配上一個 delete 來釋放，否則會導致 memory leak。
在 main 裡，new 出了一個用指針指向的對象，這個對象是在 heap 上分配的，不像在 stack 上的變量在超出作用域時自動釋放，
因此為了避免 memory leak，必須手動 delete 來釋放內存。
*/