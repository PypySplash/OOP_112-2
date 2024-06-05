#include <iostream>
#include "Rectangle.h"

using namespace std; 
 
int main()
{
  cout << "Start of main() "<< endl;
  cout << "1. ";
  Rectangle r1("Yellow",30, 40);
  cout << r1 << endl;

  cout << "2. ";
  Rectangle r2(r1);
  cout << r2 << endl;
  cout << "3. is r2 square? " << r2.isSquare() << endl;

  cout << "4. ";
  Rectangle r3;
  cout << r3 << endl;

  cout << "5. ";
  r2.changeColor("Green");
  r2.changeWidth(100);
  r2.changeLength(100);
  r3 = r2;
  cout << r3 << endl;
  
  cout << "6. is r3 square? " << r3.isSquare() << endl;
  
  Rectangle r4(2,3);
  cout << "7. " << r4 << endl;
  cout << "End of main() "<< endl;

}