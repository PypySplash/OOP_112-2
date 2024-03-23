#include <iostream>
#include <cmath>
using namespace std;

void getInput(int a[], const int& length);
double average(int a[], const int& length);
double standardDev(int a[], const int& length);

int main() {
    cout << "Your array length: ";
    int n;
    cin >> n;

    int ar[n];
    getInput(ar, n);

    cout << "mean: " << average(ar, n) << endl;
    cout << "Std: " << standardDev(ar, n);

    return 0;
}

void getInput(int a[], const int& length)
{
    cout << "Give array elements: ";
    for (int i = 0; i < length; i++)
    {
        cin >> a[i];
    }
}

double average(int a[], const int& length)
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += a[i];
    }
    return static_cast<double>(sum) / length;
}
double standardDev(int a[], const int& length)
{
    double avg = average(a, length);
    double std, temp = 0;
    for (int i = 0; i < length; i++)
    {
        temp += pow(a[i] - avg, 2) / length;
    }
    return sqrt(temp);
}
