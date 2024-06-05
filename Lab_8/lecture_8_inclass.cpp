#include <iostream>
#include <memory>
using namespace std;

int main() {
    weak_ptr<int> gw;  // gw 是個 weak pointer

    // sp is the shared_ptr handling the int object with value 42
    auto sp = make_shared<int>(42);

    gw = sp;

    // sp.reset();

    cout << "gw.use_count() = " << gw.use_count() << endl;

    // we have to make a copy of shared pointer before usage:
    if (shared_ptr<int> spt = gw.lock())
        cout << "*spt == " << *spt << endl;
    else
        cout << "gw has expired" << endl;
}