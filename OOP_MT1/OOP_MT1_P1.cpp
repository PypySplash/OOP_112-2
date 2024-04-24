#include <iostream>
#include <vector>
using namespace std;

void fillVector(vector<int>& vec, int n);
void printTriangle(vector<int>& vec, int n1, int n2);

int main()
{
    int numOfLevels;
    cout << "Number of levels: ";
    cin >> numOfLevels;
    if (numOfLevels == 0)
    {
        cout << "No pyramid!" << endl;
    }
    else
    {
        int numOfFibonacci = 0;
        for (int i = 0; i < numOfLevels; i++)
        {
            numOfFibonacci += i + 1;
        }

        vector<int> fibonacciVec(numOfFibonacci);
        fillVector(fibonacciVec, numOfFibonacci);
        // for (int i = 0; i < numOfFibonacci; i++)
        // {
        //     cout << fibonacciVec[i] << endl;
        // }
        printTriangle(fibonacciVec, numOfFibonacci, numOfLevels);
    }

}

void fillVector(vector<int>& vec, int n)
{
    vec[0] = 0;
    vec[1] = 1;
    for (int i = 2; i < n; i++)
    {
        vec[i] = vec[i - 2] + vec[i - 1];
    }
}
void printTriangle(vector<int>& vec, int numOfF, int numOfL)
{
    int index = 0;
    for (int i = 0; i < numOfL; i++)
    {
        if (i == 0)
        {
            cout << vec[index] << endl;
            index++;
        }
        if (i == 1)
        {
            cout << vec[index] << " ";
            cout << vec[index + 1] << endl;
            index += 2;
        }
        if (i == 2)
        {
            cout << vec[index] << " ";
            cout << vec[index + 1] << " ";
            cout << vec[index + 2] << endl;
            index += 3;
        }
        if (i == 3)
        {
            cout << vec[index] << " ";
            cout << vec[index+1] << " ";
            cout << vec[index+2] << " ";
            cout << vec[index+3] << endl;
            index += 4;
        }
        if (i == 4)
        {
            cout << vec[index] << " ";
            cout << vec[index+1] << " ";
            cout << vec[index+2] << " ";
            cout << vec[index+3] << " ";
            cout << vec[index+4] << endl;
            index += 5;
        }
        if (i == 5)
        {
            cout << vec[index] << " ";
            cout << vec[index+1] << " ";
            cout << vec[index+2] << " ";
            cout << vec[index+3] << " ";
            cout << vec[index+4] << " ";
            cout << vec[index+5] << endl;
            index += 6;
        }
        if (i == 6)
        {
            cout << vec[index] << " ";
            cout << vec[index+1] << " ";
            cout << vec[index+2] << " ";
            cout << vec[index+3] << " ";
            cout << vec[index+4] << " ";
            cout << vec[index+5] << " ";
            cout << vec[index+6] << endl;
            index += 7;
        }
        if (i == 7)
        {
            cout << vec[index] << " ";
            cout << vec[index+1] << " ";
            cout << vec[index+2] << " ";
            cout << vec[index+3] << " ";
            cout << vec[index+4] << " ";
            cout << vec[index+5] << " ";
            cout << vec[index+6] << " ";
            cout << vec[index+7] << endl;
            index += 8;
        }
        if (i == 8)
        {
            cout << vec[index] << " ";
            cout << vec[index+1] << " ";
            cout << vec[index+2] << " ";
            cout << vec[index+3] << " ";
            cout << vec[index+4] << " ";
            cout << vec[index+5] << " ";
            cout << vec[index+6] << " ";
            cout << vec[index+7] << " ";
            cout << vec[index+8] << endl;
            index += 9;
        }
        if (i == 9)
        {
            cout << vec[index] << " ";
            cout << vec[index+1] << " ";
            cout << vec[index+2] << " ";
            cout << vec[index+3] << " ";
            cout << vec[index+4] << " ";
            cout << vec[index+5] << " ";
            cout << vec[index+6] << " ";
            cout << vec[index+7] << " ";
            cout << vec[index+8] << " ";
            cout << vec[index+9] << endl;
            index += 10;
        }
        if (i == 10)
        {
            cout << vec[index] << " ";
            cout << vec[index+1] << " ";
            cout << vec[index+2] << " ";
            cout << vec[index+3] << " ";
            cout << vec[index+4] << " ";
            cout << vec[index+5] << " ";
            cout << vec[index+6] << " ";
            cout << vec[index+7] << " ";
            cout << vec[index+8] << " ";
            cout << vec[index+9] << " ";
            cout << vec[index+10] << endl;
            index += 11;
        }
        if (i == 11)
        {
            cout << vec[index] << " ";
            cout << vec[index+1] << " ";
            cout << vec[index+2] << " ";
            cout << vec[index+3] << " ";
            cout << vec[index+4] << " ";
            cout << vec[index+5] << " ";
            cout << vec[index+6] << " ";
            cout << vec[index+7] << " ";
            cout << vec[index+8] << " ";
            cout << vec[index+9] << " ";
            cout << vec[index+10] << " ";
            cout << vec[index+11] << endl;
            index += 12;
        }
        if (i == 12)
        {
            cout << vec[index] << " ";
            cout << vec[index+1] << " ";
            cout << vec[index+2] << " ";
            cout << vec[index+3] << " ";
            cout << vec[index+4] << " ";
            cout << vec[index+5] << " ";
            cout << vec[index+6] << " ";
            cout << vec[index+7] << " ";
            cout << vec[index+8] << " ";
            cout << vec[index+9] << " ";
            cout << vec[index+10] << " ";
            cout << vec[index+11] << " ";
            cout << vec[index+12] << endl;
            index += 13;
        }
    }
}
