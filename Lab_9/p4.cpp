#include <iostream>
using namespace std;



class VecFour
{
private:
    double x;
    double y;
    double z;
    double w;
public:
    VecFour(double x, double y, double z, double w) : x(x), y(y), z(z), w(w) {}
    VecFour() = default;
    friend ostream& operator<< (ostream& cout, const VecFour& vec) 
    {
        cout << "(" << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w << ")";
        return cout;
    }
    friend istream& operator>> (istream& cin, VecFour& vec)
    {
        cin >> vec.x >> vec.y >> vec.z >> vec.w;
        return cin;
    }
};
int main (){
VecFour a = VecFour(1.0,1.0,2.0,2.0) ;
cout << "The vector \'a\' is: " << a << endl ;
VecFour b ;
cout << "Please input a vector: " ;
cin >> b ; // 0.0,1.0,2.0,5.0
cout << "The vector you input is: " << b << endl ;
return 0 ;
}
