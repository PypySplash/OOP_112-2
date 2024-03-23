#include <iostream>
#include <vector>
using namespace std;

vector<int> rearrangeArray(const vector<int>& arr);
void printArray(const vector<int>& arr);

int main()
{
    cout << "Input: " << endl;
    cout << "n: ";
    int n;
    cin >> n;
    cout << "arr: ";
    vector<int> arr;
    for (int i = 0; i < 2 * n; i++)
    {
        int temp = 0;
        cin >> temp;
        arr.push_back(temp);
    }
    vector<int> rearrangedArray = rearrangeArray(arr);
    printArray(rearrangedArray);
}

vector<int> rearrangeArray(const vector<int>& arr)
{
    int n = arr.size() / 2;
    vector<int> final(2 * n);
    for (int i = 0; i < n; i++)
    {
        final[2 * i] = arr[i];
        final[2 * i + 1] = arr[i + n];
    }
    return final;
}

void printArray(const vector<int>& arr)
{
    cout << "[";
    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
        if (i < arr.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}