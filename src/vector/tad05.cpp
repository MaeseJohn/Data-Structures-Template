#include <iostream>

using namespace std;

#include "tporo.h"
#include "vector.h"

int
main(void)
{
  TPoro a(1, 2, 3, "rojo");
  vector<TPoro> v(5);

  v[0] = a;
  v[1] = a;
  v[2] = a;
  v[3] = a;
  v[4] = a;

  cout << v << endl;
}
