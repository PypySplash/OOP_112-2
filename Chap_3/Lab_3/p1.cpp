#include <iostream>
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

double dotProduct(Vertex v1, Vertex v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}

int main()
{
    Triangle triArr[3];

    cout << "Input for the 1st triangle: " << endl;
    cout << "Please input the x & y coordinates of the 1st vertex: ";
    cin >> triArr[0].A.x >> triArr[0].A.y;
    cout << "Please input the x & y coordinates of the 2nd vertex: ";
    cin >> triArr[0].B.x >> triArr[0].B.y;
    cout << "Please input the x & y coordinates of the 3rd vertex: ";
    cin >> triArr[0].C.x >> triArr[0].C.y;
    
    if ((((triArr[0].A.x - triArr[0].B.x) * (triArr[0].C.x - triArr[0].B.x) + (triArr[0].A.y - triArr[0].B.y) * (triArr[0].C.y - triArr[0].B.y)) == 0)
    && (((triArr[0].A.x == triArr[0].B.x) && (triArr[0].A.y == triArr[0].B.y)) == false) 
    && (((triArr[0].A.x == triArr[0].C.x) && (triArr[0].A.y == triArr[0].C.y)) == false)
    && (((triArr[0].B.x == triArr[0].C.x) && (triArr[0].B.y == triArr[0].C.y)) == false))
    {
        triArr[0].right = true;
        triArr[0].B.sign = true;
    }
    else if ((((triArr[0].B.x - triArr[0].A.x) * (triArr[0].C.x - triArr[0].A.x) + (triArr[0].B.y - triArr[0].A.y) * (triArr[0].C.y - triArr[0].A.y)) == 0)
    && (((triArr[0].A.x == triArr[0].B.x) && (triArr[0].A.y == triArr[0].B.y)) == false) 
    && (((triArr[0].A.x == triArr[0].C.x) && (triArr[0].A.y == triArr[0].C.y)) == false)
    && (((triArr[0].B.x == triArr[0].C.x) && (triArr[0].B.y == triArr[0].C.y)) == false))
    {
        triArr[0].right = true;
        triArr[0].A.sign = true;
    }
    else if ((((triArr[0].A.x - triArr[0].C.x) * (triArr[0].B.x - triArr[0].C.x) + (triArr[0].A.y - triArr[0].C.y) * (triArr[0].B.y - triArr[0].C.y)) == 0)
    && (((triArr[0].A.x == triArr[0].B.x) && (triArr[0].A.y == triArr[0].B.y)) == false) 
    && (((triArr[0].A.x == triArr[0].C.x) && (triArr[0].A.y == triArr[0].C.y)) == false)
    && (((triArr[0].B.x == triArr[0].C.x) && (triArr[0].B.y == triArr[0].C.y)) == false))
    {
        triArr[0].right = true;
        triArr[0].C.sign = true;
    }

    cout << "Input for the 2nd triangle: " << endl;
    cout << "Please input the x & y coordinates of the 1st vertex: ";
    cin >> triArr[1].A.x >> triArr[1].A.y;
    cout << "Please input the x & y coordinates of the 2nd vertex: ";
    cin >> triArr[1].B.x >> triArr[1].B.y;
    cout << "Please input the x & y coordinates of the 3rd vertex: ";
    cin >> triArr[1].C.x >> triArr[1].C.y;

    if ((((triArr[1].A.x - triArr[1].B.x) * (triArr[1].C.x - triArr[1].B.x) + (triArr[1].A.y - triArr[1].B.y) * (triArr[1].C.y - triArr[1].B.y)) == 0) 
    && (((triArr[1].A.x == triArr[1].B.x) && (triArr[1].A.y == triArr[1].B.y)) == false) 
    && (((triArr[1].A.x == triArr[1].C.x) && (triArr[1].A.y == triArr[1].C.y)) == false)
    && (((triArr[1].B.x == triArr[1].C.x) && (triArr[1].B.y == triArr[1].C.y)) == false))
    {
        triArr[1].right = true;
        triArr[1].B.sign = true;
    }
    else if ((((triArr[1].B.x - triArr[1].A.x) * (triArr[1].C.x - triArr[1].A.x) + (triArr[1].B.y - triArr[1].A.y) * (triArr[1].C.y - triArr[1].A.y)) == 0)
    && (((triArr[1].A.x == triArr[1].B.x) && (triArr[1].A.y == triArr[1].B.y)) == false) 
    && (((triArr[1].A.x == triArr[1].C.x) && (triArr[1].A.y == triArr[1].C.y)) == false)
    && (((triArr[1].B.x == triArr[1].C.x) && (triArr[1].B.y == triArr[1].C.y)) == false))
    {
        triArr[1].right = true;
        triArr[1].A.sign = true;
    }
    else if ((((triArr[1].A.x - triArr[1].C.x) * (triArr[1].B.x - triArr[1].C.x) + (triArr[1].A.y - triArr[1].C.y) * (triArr[1].B.y - triArr[1].C.y)) == 0)
    && (((triArr[1].A.x == triArr[1].B.x) && (triArr[1].A.y == triArr[1].B.y)) == false) 
    && (((triArr[1].A.x == triArr[1].C.x) && (triArr[1].A.y == triArr[1].C.y)) == false)
    && (((triArr[1].B.x == triArr[1].C.x) && (triArr[1].B.y == triArr[1].C.y)) == false))
    {
        triArr[1].right = true;
        triArr[1].C.sign = true;
    }

    cout << "Input for the 3rd triangle: " << endl;
    cout << "Please input the x & y coordinates of the 1st vertex: ";
    cin >> triArr[2].A.x >> triArr[2].A.y;
    cout << "Please input the x & y coordinates of the 2nd vertex: ";
    cin >> triArr[2].B.x >> triArr[2].B.y;
    cout << "Please input the x & y coordinates of the 3rd vertex: ";
    cin >> triArr[2].C.x >> triArr[2].C.y;
    if ((((triArr[2].A.x - triArr[2].B.x) * (triArr[2].C.x - triArr[2].B.x) + (triArr[2].A.y - triArr[2].B.y) * (triArr[2].C.y - triArr[2].B.y)) == 0)
    && (((triArr[2].A.x == triArr[2].B.x) && (triArr[2].A.y == triArr[2].B.y)) == false) 
    && (((triArr[2].A.x == triArr[2].C.x) && (triArr[2].A.y == triArr[2].C.y)) == false)
    && (((triArr[2].B.x == triArr[2].C.x) && (triArr[2].B.y == triArr[2].C.y)) == false))
    {
        triArr[2].right = true;
        triArr[2].B.sign = true;
    }
    else if ((((triArr[2].B.x - triArr[2].A.x) * (triArr[2].C.x - triArr[2].A.x) + (triArr[2].B.y - triArr[2].A.y) * (triArr[2].C.y - triArr[2].A.y)) == 0)
    && (((triArr[2].A.x == triArr[2].B.x) && (triArr[2].A.y == triArr[2].B.y)) == false) 
    && (((triArr[2].A.x == triArr[2].C.x) && (triArr[2].A.y == triArr[2].C.y)) == false)
    && (((triArr[2].B.x == triArr[2].C.x) && (triArr[2].B.y == triArr[2].C.y)) == false))
    {
        triArr[2].right = true;
        triArr[2].A.sign = true;
    }
    else if ((((triArr[2].A.x - triArr[2].C.x) * (triArr[2].B.x - triArr[2].C.x) + (triArr[2].A.y - triArr[2].C.y) * (triArr[2].B.y - triArr[2].C.y)) == 0)
    && (((triArr[2].A.x == triArr[2].B.x) && (triArr[2].A.y == triArr[2].B.y)) == false) 
    && (((triArr[2].A.x == triArr[2].C.x) && (triArr[2].A.y == triArr[2].C.y)) == false)
    && (((triArr[2].B.x == triArr[2].C.x) && (triArr[2].B.y == triArr[2].C.y)) == false))
    {
        triArr[2].right = true;
        triArr[2].C.sign = true;
    }

    cout << "Done reading Triangles." << endl;
    if (triArr[0].right)
    {
        cout << "Triangle 1 is a right triangle!" << endl;
        if (triArr[0].A.sign) cout << "The right angle of triangle 1 is at the Vertex 1" << endl;
        if (triArr[0].B.sign) cout << "The right angle of triangle 1 is at the Vertex 2" << endl;
        if (triArr[0].C.sign) cout << "The right angle of triangle 1 is at the Vertex 3" << endl;
    }
    else
    {
        cout << "Triangle 1 is NOT a right triangle!" << endl;
    }
    
    if (triArr[1].right)
    {
        cout << "Triangle 2 is a right triangle!" << endl;
        if (triArr[1].A.sign) cout << "The right angle of triangle 2 is at the Vertex 1" << endl;
        if (triArr[1].B.sign) cout << "The right angle of triangle 2 is at the Vertex 2" << endl;
        if (triArr[1].C.sign) cout << "The right angle of triangle 2 is at the Vertex 3" << endl;
    }
    else
    {
        cout << "Triangle 2 is NOT a right triangle!" << endl;
    }

    if (triArr[2].right)
    {
        cout << "Triangle 3 is a right triangle!" << endl;
        if (triArr[2].A.sign) cout << "The right angle of triangle 3 is at the Vertex 1" << endl;
        if (triArr[2].B.sign) cout << "The right angle of triangle 3 is at the Vertex 3" << endl;
        if (triArr[2].C.sign) cout << "The right angle of triangle 3 is at the Vertex 3" << endl;
    }
    else
    {
        cout << "Triangle 3 is NOT a right triangle!" << endl;
    }
}
