#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector<string> split(const string& str, char delim)
{
    vector<string> tokens;
    string token;
    for (char ch : str)
    {
        if (ch == delim)
        {
            if (!token.empty())
            {
                tokens.push_back(token);
                token.clear();
            }
        } else {
            token += ch;
        }
    }
    if (!token.empty()) 
    {
        tokens.push_back(token);
    }
    return tokens;
}

int main()
{
    string fileName;
    cout << "Please input file name: ";
    cin >> fileName;
    ifstream file(fileName);  // 打開檔案

    string scores;
    getline(file, scores);
    file.close();

    vector<string> scoreStrings = split(scores, ',');
    double total = 0;

    cout << "scores read: ";
    for (const string& scoreStr : scoreStrings)
    {
        total += stod(scoreStr);
        cout << scoreStr << " ";
    }
    cout << endl;
    double average = total / scoreStrings.size();
    cout << "There are " << scoreStrings.size() << " scores and the average is " << average << endl;
}