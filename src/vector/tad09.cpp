#include <iostream>

using namespace std;

#include "tporo.h"
#include "vector.h"

int
main(void)
{
  TPoro a(1, 2, 3, "rojo");

  vector<TPoro> p;
  vector<TPoro> v(5);
  vector<TPoro> b(v);

  v[0] = a;
  v[1] = a;
  v[2] = a;

  vector<TPoro> x(v);
  vector<TPoro> z;

  cout << "******TESTING CONSTRUCTORS, OPERATOR[], OPERATOR= AND GETTER******" << endl;

  cout << p.size() << endl;
  cout << p << endl;

  cout << b.size() << endl;
  cout << b << endl;

  cout << v.size() << endl;
  v[3] = a;
  v[4] = a;
  cout << v.size() << endl;
  cout << v << endl;

  cout << x.size() << endl;
  cout << x << endl;

  z = v;
  cout << z.size() << endl;
  cout << z << endl;
}
