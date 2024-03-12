#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    // ifstream file("matrix.txt");
    ifstream file("matrix2.txt");
    // ofstream outFile("matrix_out.txt");
    ofstream outFile("matrix2_out.txt");
    int r, c;

    if (file.is_open())
    {
        file >> r >> c;
        vector<vector<int> > matrix(r, vector<int>(c));

        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++) 
                file >> matrix[i][j];
    
        vector<vector<int> > transMatrix(c, vector<int>(r));
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++) 
            {
                transMatrix[j][i] = matrix[i][j];
            }
            cout << endl;
        }
        if (outFile.is_open())
        {
            for (int i = 0; i < c; i++)
            {
                for (int j = 0; j < r; j++)
                {
                    outFile << transMatrix[i][j] << " ";
                }
                outFile << endl;
            }
            outFile.close();
        }
    }
}
