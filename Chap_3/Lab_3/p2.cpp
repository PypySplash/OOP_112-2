#include <iostream>
#include <vector>
using namespace std;

struct Vertex 
{
    double x;
    double y;
    bool sign = false;
};

struct Triangle 
{
    Vertex A;
    Vertex B;
    Vertex C;
    bool right = false;
};

double distanceSquared(Vertex v1, Vertex v2) 
{
    return (v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y);
}

int main()
{
    int count = 0;
    cout << "How many Triangles will you input? ";
    cin >> count;

    vector<Triangle> triVec(count);

    for (auto iter = triVec.begin(); iter != triVec.end(); ++iter)
    {
        int index = distance(triVec.begin(), iter) + 1;
        cout << "Input for the No. " << index << " triangle: " << endl;
        cout << "Please input the x & y coordinates of the 1st vertex: ";
        cin >> iter->A.x >> iter->A.y;
        cout << "Please input the x & y coordinates of the 2nd vertex: ";
        cin >> iter->B.x >> iter->B.y;
        cout << "Please input the x & y coordinates of the 3rd vertex: ";
        cin >> iter->C.x >> iter->C.y;
        
        if ((((iter->A.x - iter->B.x) * (iter->C.x - iter->B.x) + (iter->A.y - iter->B.y) * (iter->C.y - iter->B.y)) == 0)
        && (((iter->A.x == iter->B.x) && (iter->A.y == iter->B.y)) == false) 
        && (((iter->A.x == iter->C.x) && (iter->A.y == iter->C.y)) == false)
        && (((iter->B.x == iter->C.x) && (iter->B.y == iter->C.y)) == false))
        {
            iter->right = true;
            iter->B.sign = true;
        }
        else if ((((iter->B.x - iter->A.x) * (iter->C.x - iter->A.x) + (iter->B.y - iter->A.y) * (iter->C.y - iter->A.y)) == 0)
        && (((iter->A.x == iter->B.x) && (iter->A.y == iter->B.y)) == false) 
        && (((iter->A.x == iter->C.x) && (iter->A.y == iter->C.y)) == false)
        && (((iter->B.x == iter->C.x) && (iter->B.y == iter->C.y)) == false))
        {
            iter->right = true;
            iter->A.sign = true;
        }
        else if ((((iter->A.x - iter->C.x) * (iter->B.x - iter->C.x) + (iter->A.y - iter->C.y) * (iter->B.y - iter->C.y)) == 0)
        && (((iter->A.x == iter->B.x) && (iter->A.y == iter->B.y)) == false) 
        && (((iter->A.x == iter->C.x) && (iter->A.y == iter->C.y)) == false)
        && (((iter->B.x == iter->C.x) && (iter->B.y == iter->C.y)) == false))
        {
            iter->right = true;
            iter->C.sign = true;
        }
    }

    cout << "Done reading Triangles." << endl;

    for (auto iter = triVec.begin(); iter != triVec.end(); ++iter)
    {
        int index = distance(triVec.begin(), iter) + 1;
        if (iter->right)
        {
            cout << "Triangle " << index << " is a right triangle!" << endl;
            // if (triVec[i].A.sign) cout << "The right angle of triangle " << i + 1 << " is at the Vertex 1" << endl;
            // if (triVec[i].B.sign) cout << "The right angle of triangle " << i + 1<< " is at the Vertex 2" << endl;
            // if (triVec[i].C.sign) cout << "The right angle of triangle " << i + 1<< " is at the Vertex 3" << endl;
        }
        else
        {
            cout << "Triangle " << index << " is NOT a right triangle!" << endl;
        }
    }
}
