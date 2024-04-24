#include <iostream>
using namespace std;



struct IntArray 
{
    int* ia; // pointer to first element of int array
    size_t n; // size of the array
};
IntArray creatIntArray();
int findMax(const IntArray&);
void printIntArray(const IntArray&);
void deleteIntArray(IntArray&);

IntArray creatIntArray() 
{
    IntArray array;
    cout << "How many integers do you want to input: ";
    cin >> array.n;
    array.ia = new int [array.n];
    cout << "Please input the integers: ";

    for (size_t i = 0; i < array.n; i++)
    {
        cin >> array.ia[i];
    }
    return array;
}

int findMax(const IntArray& array) 
{
    int maxIndex = 0;
    for (size_t i = 1; i < array.n; i++)
    {
        if (array.ia[i] > array.ia[maxIndex]) 
        {
            maxIndex = i;
        }
    }
    return maxIndex;
}

void printIntArray(const IntArray& array)
{
    cout << "Integer array: ";
    for (size_t i = 0; i < array.n; i++)
    {
        cout << array.ia[i] << " ";
    }
    cout << endl;
}

void deleteIntArray(IntArray& array)
{
    delete[] array.ia;
    array.ia = nullptr;
    array.n = 0;
}

int main(){
    IntArray intArray = creatIntArray();
    int i = findMax(intArray);
    cout << "Max value in integer array is: " << intArray.ia[i] << endl;
    printIntArray(intArray);
    deleteIntArray(intArray);
    return 0;
}
