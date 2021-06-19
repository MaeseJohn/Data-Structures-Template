#include <iostream>

using namespace std;

#include "tporo.h"

int
main(void)
{
  TPoro a1(1, 2, 3, "rojo");
  TPoro a2(1, 2, 3, "rojo");
  TPoro a3(1, 2, 3, "rajo");

  TPoro b1(1, 2, 3);
  TPoro b2(1, 2, 3);

  TPoro c1(7, 6, 1, "rbfdjo");
  TPoro c2(7, 6, 1, "rojo");
  TPoro c3(7, 6, 1, "rojo");

  cout << "******TESTING CONSTRUCTORS AND OPERATOR==******" << endl;
  
  if(a1 == a2) // true
  {
  	cout << "iguales" << endl;
  }

  if(a1 != a3) //false
  {
    cout << "diferentes" << endl;
  }

  if(b1 == b2) //true
  {
  	cout << "iguales" << endl;
  }

  if(c1 != c2) //false
  {
  	cout << "diferentes" << endl;
  }

  if(c2 == c3) //true
  {
    cout << "iguales" << endl;
  }

  if(a1 != b1) //true
  {
  	cout << "diferentes" << endl;
  }

  if(c1 != b1) //true
  {
  	cout << "diferentes" << endl;
  }

  if(a1 != c1) //true
  {
  	cout << "diferentes" << endl;
  }
}
