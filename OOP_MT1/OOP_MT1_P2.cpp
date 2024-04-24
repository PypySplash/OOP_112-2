#include <iostream>
#include <vector>
using namespace std;

int seeSawBalancing(vector<int> vec, int n);

int main()
{
    int numOfStone;
    cout << "How many stones: ";
    cin >> numOfStone;
    
    vector<int> stoneVec;
    cout << "Weights for the stones: ";
    for (int i = 0; i < numOfStone; i++)
    {
        int weightOfStone;
        cin >> weightOfStone;
        stoneVec.push_back(weightOfStone);
    }
    int loc = -1;
    loc = seeSawBalancing(stoneVec, numOfStone);
    cout << loc;
}

int seeSawBalancing(vector<int> vec, int n)
{
    
    for (int i = 1; i < n - 1; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                sum += vec[j] * (i-j);
            }
        }
        if (sum == 0)
        {
            return i + 1;
            break;
        }
        if (i == n - 2 && sum != 0)
        {
            return -1;
        }
    }
}
