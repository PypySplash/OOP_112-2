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
    friend VecFour operator*(double scalar, const VecFour& vec)
    {
        return VecFour(vec.x * scalar, vec.y * scalar, vec.z * scalar, vec.w * scalar);
    }
    VecFour& operator*=(const VecFour& other)
    {
        x *= other.x;
        y *= other.y;
        z *= other.z;
        w *= other.w;
        return *this;
    }
};
int main(){
VecFour a = VecFour(1.0,1.0,2.0,2.0) ;
VecFour c = 2.5*a ;
cout << "The vector \'c\' is : " << c << endl ;
c *= a;
cout << "The vector \'c\' changes to : " << c << endl ;
VecFour d ; // 0.0,0.0,0.0,0.0
cout << "The vector \'d\' is : " << d << endl ;
return 0 ;
}
