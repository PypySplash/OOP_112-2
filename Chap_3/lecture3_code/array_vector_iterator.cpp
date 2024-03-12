#include <iostream>
#include <vector>
#include <iterator>
#include <cstdlib>

using namespace std;

const int NUM_SIZE = 8;

int main()
{   
    //int v[NUM_SIZE] = {};
    int v[NUM_SIZE];

    //vector<int> v(NUM_SIZE); 
    //vector<int> v; 
    //v.reserve(NUM_SIZE); 
    
    auto beg = begin(v); // pointer to the first element in ia  
    auto last = end(v); // pointer one past the last element in ia

    int sum = 0;

    srand(7); //setting the random seed so that we can see identical results


    cout << "Generated values: ";
    while(beg != last){
        *beg = rand() % 100; // value in the range 0 to 99

        cout << *beg << " ";

        sum += *beg;
        beg++;
    }
    cout << endl;

    beg = begin(v);
    double avg = 1.0*sum/NUM_SIZE;

    cout << "The average is: " << avg << endl;

    int count = 0;
    while(beg != last){
        if(*beg >= avg) count += 1;
        beg++;
    }

    cout << "There are " << count << " values larger than the average." << endl;
    
    return 0;
}
