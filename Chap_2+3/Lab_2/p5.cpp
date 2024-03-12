#include <iostream>
#include <vector>
using namespace std;

void swap(int* num1, int* num2) 
{
    // Please fill this blank
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int main()
{
    vector<int> vec;
    int input = 0;
    cout << "Enter the elements: " << endl;
    while (cin >> input)
    {
        vec.push_back(input);
    }
    for (int i = 0; i < vec.size() - 1; i++)  // 若有 n 個數，index只能走到第 n - 1 個，故需 - 1
    {
        for (int j = 0; j < vec.size() - i - 1; j++)
        {
            if (vec[j] > vec[j + 1]) 
            {
                swap(vec[j], vec[j + 1]);
            }
        }
    }
    
    cout << "Sorted vector:" << " ";
    for (auto i : vec)
    {
        cout << i << " ";
    }
    cout << endl;
}
