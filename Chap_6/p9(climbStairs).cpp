#include <iostream>
#include <chrono>
using namespace std;

int climbStairs(int n);

int main()
{
    auto start_time = chrono::high_resolution_clock::now();
    // code to measure the running time
    int num;
    cout << "Input: n = ";
    cin >> num;

    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
    cout << "Running time: " << duration << " microseconds" << endl;

    cout << "Output: " << climbStairs(num) << endl;
}

int climbStairs(int n)
{
    if (n <= 2) return n;
    return climbStairs(n - 1) + climbStairs(n - 2);
}
