#include <iostream>
#include <memory>
using namespace std;

const int INPUT_AMOUNT = 3;

struct Node 
{
    int value;
    shared_ptr<Node> next;
};



int main() {
    // Please fill this blank to establish the linked list
    auto head = make_shared<Node>();
    cin >> head->value;
    head->next = make_shared<Node>();
    cin >> head->next->value;
    head->next->next = make_shared<Node>();
    cin >> head->next->next->value;
    head->next->next->next = nullptr;

    shared_ptr<Node> curr = head;
    while (curr) 
    {
        // Please fill this blank (this while loop prints out the list)
        cout << curr->value << " ";
        curr = curr->next;
    }
    cout << endl;
    return 0;
}
