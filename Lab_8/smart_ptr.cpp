#include <iostream>
#include <memory>

class B; // Forward declaration

class A {
public:
    std::weak_ptr<B> b_ptr;  // Changed from shared_ptr to weak_ptr
    A() { std::cout << "A Constructor\n"; }
    ~A() { std::cout << "A Destructor\n"; }
    void connect(std::shared_ptr<B> b) {
        b_ptr = b;
    }
};

class B {
public:
    std::shared_ptr<A> a_ptr;
    B() { std::cout << "B Constructor\n"; }
    ~B() { std::cout << "B Destructor\n"; }
    void connect(std::shared_ptr<A> a) {
        a_ptr = a;
    }
};

using namespace std;

int main() {
    auto a = std::make_shared<A>();
    auto b = std::make_shared<B>();
    a->connect(b);  // class A 被 a 以及 B 裡面的 a ptr 使用，故 use_count = 2
    b->connect(a);  // class B 被 b 以及 A 裡面的 b ptr 使用，但 b ptr 為 weak ptr，故 use_count = 1
    cout << a.use_count() << endl;  // 2
    cout << b.use_count() << endl;  // 1
    return 0;
}