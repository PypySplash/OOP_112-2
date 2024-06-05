/*
The rule of three3 is a rule of thumb in C++. It claims that if a class defines any of the
following then it should explicitly define all three:
• destructor
• copy constructor
• copy assignment operator
Now we use an example to demonstrate the Rule of 3 for smart pointers.
*/



#include <iostream>
#include <memory> // For smart pointers



// base/parent class
class ResourceHolder 
{
public:
    // Constructor
    ResourceHolder(size_t size) : size(size), data(new int[size])
    {
        std::cout << "ResourceHolder constructed with size " <<
        size << std::endl;
    }
    // Destructor
    ~ResourceHolder() 
    {
        std::cout << "ResourceHolder destructor" << std::endl;
    }
    // Copy constructor
    ResourceHolder(const ResourceHolder& other) : size(other.size), data(new int[other.size]) 
    {
        std::copy(other.data.get(), other.data.get() + other.size,
        data.get());
        std::cout << "ResourceHolder copy construct" << std::endl;
    }
    // Copy assignment operator
    ResourceHolder& operator=(const ResourceHolder& other) 
    {
        if (this == &other) 
        {
            return *this;
        }
        size = other.size;
        data.reset(new int[size]);
        std::copy(other.data.get(), other.data.get() + other.size,
        data.get());
        std::cout << "ResourceHolder assignment operator" <<
        std::endl;
        return *this;
    }
    void setValue(size_t index, int value) 
    {
        if (index < size) 
        {
            data[index] = value;
        }
    }
    int getValue(size_t index) const 
    {
        if (index < size) 
        {
            return data[index];
        }
        return -1; // For simplicity, returning -1 for invalid index
    }
protected:
    size_t size;
    std::unique_ptr<int[]> data;
};
    // derived/child class
class ExtendedResourceHolder : public ResourceHolder 
{
public:
    // Constructor
    ExtendedResourceHolder(size_t size, size_t additionalSize) 
    : ResourceHolder(size), additionalSize(additionalSize), additionalData(new int[additionalSize]) 
    {
        std::cout << "ExtendedResourceHolder constructed with additional size " << additionalSize << std::endl;
    }
    // Destructor
    ~ExtendedResourceHolder() 
    {
        std::cout << "ExtendedResourceHolder destructor" <<
        std::endl;
    }
    // Copy constructor
    ExtendedResourceHolder(const ExtendedResourceHolder& other) 
    : ResourceHolder(other), additionalSize(other.additionalSize), additionalData(new int[other.additionalSize]) 
    {
        std::copy(other.additionalData.get(),
        other.additionalData.get() + other.additionalSize,
        additionalData.get());
        std::cout << "ExtendedResourceHolder copy construct" <<
        std::endl;
    }
    // Copy assignment operator
    ExtendedResourceHolder& operator=(const ExtendedResourceHolder& other) 
    {
        if (this == &other) 
        {
            return *this;
        }
        ResourceHolder::operator=(other);
        additionalSize = other.additionalSize;
        additionalData.reset(new int[additionalSize]);
        std::copy(other.additionalData.get(), other.additionalData.get() + other.additionalSize, additionalData.get());
        std::cout << "ExtendedResourceHolder assignment operator" << std::endl;
        return *this;
    }

    void setAdditionalValue(size_t index, int value) 
    {
        if (index < additionalSize) 
        {
            additionalData[index] = value;
        }
    }

    int getAdditionalValue(size_t index) const 
    {
        if (index < additionalSize) 
        {
            return additionalData[index];
        }
        return -1; // For simplicity, returning -1 for invalid index
    }

private:
    size_t additionalSize;
    std::unique_ptr<int[]> additionalData;
};


// main function
using namespace std;
int main() 
{
    {
    cout << "1------------------------------------" << endl;
    ExtendedResourceHolder holder1(10, 5);
    holder1.setValue(0, 100);
    holder1.setAdditionalValue(0, 200);
    cout << "2------------------------------------" << endl;
    // Copy constructor
    ExtendedResourceHolder holder2 = holder1;
    cout << "3------------------------------------" << endl;
    ExtendedResourceHolder holder3(5, 3);
    cout << "4------------------------------------" << endl;
    holder3 = holder1; // Copy assignment operator
    cout << "holder1 value: " << holder1.getValue(0) << ", additional: " << holder1.getAdditionalValue(0) << endl;
    cout << "holder2 value: " << holder2.getValue(0) << ", additional: " << holder2.getAdditionalValue(0) << endl;
    cout << "holder3 value: " << holder3.getValue(0) << ", additional: " << holder3.getAdditionalValue(0) << endl;
    cout << "5------------------------------------" << endl;
    }

    // Scope ends here, destructors will be called automatically

    cout << "Exiting main!!" << endl;
    return 0;
}