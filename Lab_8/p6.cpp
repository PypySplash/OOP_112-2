#include <iostream>
#include <memory>
using namespace std;



class Wife;  // forward declaration
class Husband {
private:
    string name;
    shared_ptr<Wife> wife;  // 使用 weak_ptr 来避免循環引用
public:
    Husband(const string& n) : name(n) {
        cout << "Husband " << name << " constructor called." << endl;
    }
    void setWife(const shared_ptr<Wife>& w);
    void showWife();
    string getName() const { return name; }
    ~Husband() {
        cout << "Husband " << name << " destructor called." << endl;
    }
};

class Wife {
private:
    string name;
    // weak_ptr<Husband> husband;  // 使用 weak_ptr 来避免循環引用
    weak_ptr<Husband> husband;  // 用于控制 Husband 的生命周期
public:
    Wife(const string& n, shared_ptr<Husband> h) : name(n), husband(h) {
        cout << "Wife " << name << " constructor called." << endl;
    }
    void setHusband(const shared_ptr<Husband>& h);
    void showHusband();
    string getName() const { return name; }
    ~Wife() {
        husband.reset();  // 先釋放 Husband 的 shared_ptr
        cout << "Wife " << name << " destructor called." << endl;
    }
};

void Husband::setWife(const shared_ptr<Wife>& w) {
    wife = w;  // 設置 wife 属性
    cout << name << " has his wife set." << endl;
}

void Husband::showWife() {
    // shared_ptr<Wife> sp = wife.lock();  // 將 weak_ptr 轉為 shared_ptr 以使用
    // if (sp) {  // 確認 shared_ptr 是有效的
        cout << "Husband " << name << " has wife named " << wife->getName() << endl;
    // }
}

void Wife::setHusband(const shared_ptr<Husband>& h) {
    //  = h;  // 設置 husband 属性
    cout << name << " has her husband set." << endl;
}

void Wife::showHusband() {
    auto sp = husband.lock();  // 將 weak_ptr 轉為 shared_ptr 以使用
    if (sp) 
    {  // 確認 shared_ptr 是有效的
        cout << "Wife " << name << " has husband named " << sp->getName() << endl;
    } 
    else {
        cout << "Wife " << name << " does not have a husband linked." << endl;
    }
}

int main() {
    shared_ptr<Husband> husband = make_shared<Husband>("John");
    shared_ptr<Wife> wife = make_shared<Wife>("Jane", husband);
    
    husband->setWife(wife);
    wife->setHusband(husband);

    husband->showWife();
    wife->showHusband();
    
    return 0;
}
