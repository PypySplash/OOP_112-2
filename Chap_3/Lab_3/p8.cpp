#include <iostream>
#include <string>
using namespace std;

string encrypt(const string& input, int key)
{
    string encrypted = "";
    for (char c : input)
    {
        char encryptChar = c + key;
        encrypted += encryptChar;
    }
    return encrypted;
}

int main()
{
    string input;
    getline(cin, input);

    int K = 7;
    string encrypted = encrypt(input, K);
    cout << encrypted << endl;
}
