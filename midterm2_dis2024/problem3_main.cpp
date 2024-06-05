#include <iostream>
#include <vector>
   
// fill in
const int CAPACITY = 100;

using namespace std;

class SharedArray 
{
private:
    int size;
    int* data;
public:
    // Default Constructor
    SharedArray() : size(CAPACITY), data(new int[CAPACITY]())
    {
        cout << "Default Constructor is called" << endl;
    }
    SharedArray(int s) : size(s), data(new int[s]())
    {
        cout << "Constructor is called" << endl;
    }
    // copy constructor(shallow copy)
    // 這裡必須是 const
    SharedArray(const SharedArray& other) : size(other.size), data(other.data)  
    {
        cout << "Copy Constructor is called - Shallow copy" << endl;
    }
    // // copy constructor(deep copy)
    // SharedArray(const SharedArray& other) : size(other.size), data(new int[other.size])
    // {
    //     for (int i = 0; i < size; ++i) {
    //         data[i] = other.data[i];
    //     }
    //     cout << "Copy Constructor is called - Deep copy" << endl;
    // }
    // Copy assignment operator
    SharedArray& operator=(const SharedArray& other)
    {
        if (this != &other)
        {
            delete this->data;
            this->data = new int (*other.data);
        }
        cout << "Copy Assignment for " << *other.data << endl;
        return *this;
    }
    // Move constructor
    SharedArray (SharedArray && other) : data(other.data)
    {
        cout << "Move Constructor for " << *other.data << endl;
        other.data = nullptr;
    }
    // Move Assignment operator
    SharedArray& operator=(SharedArray && other)
    {
        if (this != &other)
        {
            delete this->data;
            this->data = other.data;
            other.data = nullptr;
        }
        cout << "Move Assignment"<< endl;
        return *this;
    }
    // subscript operator
    int &operator[] (const size_t index) { return data[index];}
    const int &operator[] (const size_t index) const 
    {
        return data[index];
    }
    ~SharedArray()
    {
        if (data != nullptr)
            cout << "Destructor is called " << "and clean up is done" << endl;
        else
            cout << "Destructor is called " << "but data is still in use by other object" << endl;
        delete data;
    }
    friend ostream& operator<<(ostream& os, const SharedArray& sa) {
        int outputSize = min(sa.size, 5); // 確保最多只輸出5個元素
        int count = 0;
        for (int i = 0; i < outputSize; i++) {
            os << sa.data[i] << " ";
            if (sa.data[i] != 0)
                count++;
            if (i == 4)
            {
                os << endl;
                os << "instances left: " << count << endl;
            }
        }
        return os;
    }
};

SharedArray create() {
      return SharedArray(5);
}

int main(){
    SharedArray m;
    cout << "before call to create()" << endl;
    m = create();
    m[0] = 5;
    cout << "m: " << m;
    // const SharedArray n(m);
    // m[0] = 1;
    // m[2] = n[0];
    // cout << "m: " << m;
    // cout << "n: " << n;
    // SharedArray o;
    // o = m;
    // cout << "o: " << o;
    // SharedArray p = move(create());
    // cout << "before returning from main" << endl;
    return 0; 
}
