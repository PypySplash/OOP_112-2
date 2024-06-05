#include <iostream>
using namespace std;
#include <vector>

const int CAPACITY = 100;

// fill in
class MyVector 
{
private:
    double* doubleArray;
    int size;
public:
    MyVector() : size(0) 
    {
        doubleArray = new double[CAPACITY];
    }
    MyVector(int s) : size(s)
    {
        doubleArray = new double[CAPACITY];
    }
    ~MyVector()
    {
        cout << "cleaning up MyVector of size " << size << endl;
        delete [] doubleArray;
    }
    // assignment operator
    // subscription operator
    double& operator[](int index)
    {
      if (index < 0 || index >= size)
      {
          cout << "out of range" << endl;
      }
      return doubleArray[index];
    }
    void printMyVector()
    {
        if (size == 0) cout << "MyVector has 0 size";
        else
        {
            cout << "printing MyVector: ";
            for (int i = 0; i < size; i++)
            {
                cout << doubleArray[i] << " ";
            }
        }
        cout << endl;
    }
    void resize(int s)
    {
        size = s;
        // doubleArray = new double[CAPACITY];
    }
};

using namespace std;

int main() {
  MyVector vec(5);
  vec[0] = 0.2;
  vec[1] = 3.1;

  vec.printMyVector();
  
  vec.resize(8);
  vec[6] = 0.4;
  vec[7] = 3.9;
  vec.printMyVector();

  MyVector vec2;
  vec2.printMyVector();
  vec2.resize(2);
  vec2[1] = 3;
  vec2.printMyVector();
  
  return 0;
}