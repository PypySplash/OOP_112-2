#include <iostream>
#include <queue>
using namespace std;

int main() 
{
    //priority_queue<int, vector<int>, greater<int>> pq;
    priority_queue<int> pq;
    pq.push(10);
    pq.push(30);
    pq.push(50);
    cout << "Size: " << pq.size() << std::endl;
    cout << "Top: " << pq.top() << std::endl;
    cout << "Elements of queue: ";
    while (!pq.empty()) 
    {
        cout << pq.top() << ' ';
        pq.pop();
    }
}