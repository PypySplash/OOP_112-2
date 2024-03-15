#include <iostream>
#include <cmath>
using namespace std;

void getInput(vector<int>& v, const int& length);
double average(const vector<int>& v);
double standardDev(const vector<int>& v);

int main() {
    cout << "Your vector length: ";
    int n;
    cin >> n;

    vector<int> vec;
    getInput(vec, n);

    cout << "mean: " << average(vec) << endl;
    cout << "Std: " << standardDev(vec);

    return 0;
}

void getInput(vector<int>& v, const int& length)
{
    cout << "Give vector elements: ";
    for (int i = 0; i < length; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
}
double average(const vector<int>& v)
{
    double sum = 0;
    int count = 0;
    for (auto vi : v)
    {
        sum += vi;
        count++;
        
    }
    return sum / static_cast<double>(count);
}
double standardDev(const vector<int>& v)
{
    double avg = average(v);
    double temp = 0;
    for (auto vi : v)
    {
        temp += pow(vi - avg, 2) / v.size();
    }
    return sqrt(temp);
}
