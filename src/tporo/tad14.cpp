#include <iostream>

using namespace std;

#include "tporo.h"

int
main(void)
{
  TPoro a1(1, 2, 3, "rojo");
  TPoro a2 = a1;
  TPoro a3(1, 2, 3, "rajo");

  TPoro b1(1, 2, 3);
  TPoro b2 = b1;

  cout << "******TESTING SETTERS******" << endl;
  
  a1.Posicion(9, 8);
  cout << a1 << endl;

  a1.Volumen(9.6);
  cout << a1 << endl;

  a1.Color("AmAriLLO");
  cout << a1 << endl;

  cout << a2 << endl;
  a2.Volumen(-29.7);
  cout << a2 << endl;

  cout << b1 << endl;
  b1.Color("vErDE");
  cout << b1 << endl;

  
}
