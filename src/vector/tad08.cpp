#include <iostream>

using namespace std;

#include "tporo.h"
#include "vector.h"

int
main(void)
{
  TPoro a(1, 2, 3, "rojo");
  vector<TPoro> v(5), w;

  cout << "Longitud: " << v.size() << endl;
  cout << "Longitud: " << w.size() << endl;

  w = v;

  cout << "Longitud: " << v.size() << endl;
  cout << "Longitud: " << w.size() << endl;
}
