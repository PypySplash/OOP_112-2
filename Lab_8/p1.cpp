#include <iostream>
#include <vector>
using namespace std;



class PFArrayD 
{
private:
    vector<double> vec;
public:
    // Default constructor
    PFArrayD()
    {
        // Fill in the blank
        vec.reserve(50);
        cout << "PFArrayD()" << endl
             << "Allocate 50 doubles" << endl;
    }
    // Constructor with unsigned argument
    PFArrayD(unsigned cap)
    {
        // Fill in the blank
        vec.reserve(cap);
        cout << "PFArrayD(unsigned)" << endl
             << "Allocate 30 doubles" << endl;
    }

    void addElement(double ele) 
    {
        // Fill in the blank
        vec.push_back(ele);
    }
    int getCapacity() 
    {
        // Fill in the blank
        return vec.capacity();
    }
    int getNumberUsed() 
    {
        // Fill in the blank
        return vec.size();
    }
};



int main() 
{
    PFArrayD pfa1;
    pfa1.addElement(1.0);
    pfa1.addElement(2.0);
    cout << "Capacity for pfa1: " << pfa1.getCapacity() << endl;
    cout << "Elements used in pfa1: " << pfa1.getNumberUsed() << endl;
    cout << "----------------" << endl;

    PFArrayD pfa2(30);
    pfa2.addElement(3.0);
    cout << "Capacity for pfa2: " << pfa2.getCapacity() << endl;
    cout << "Elements used in pfa2: " << pfa2.getNumberUsed() << endl;

    return 0;
}
