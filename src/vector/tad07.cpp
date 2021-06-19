#include <iostream>

using namespace std;

#include "tporo.h"
#include "vector.h"

int
main(void)
{
  TPoro a(1, 2, 3, "rojo");
  vector<TPoro> v(5);

  cout << "Cantidad: " << v.size() << endl;

  v[0] = a;
  cout << "Cantidad: " << v.size() << endl;

  v[1] = a;
  cout << "Cantidad: " << v.size() << endl;

  v[2] = a;
  cout << "Cantidad: " << v.size() << endl;

  v[3] = a;
  cout << "Cantidad: " << v.size() << endl;

  v[4] = a;
  cout << "Cantidad: " << v.size() << endl;
}
