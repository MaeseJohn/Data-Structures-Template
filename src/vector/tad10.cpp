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

  vector<TPoro> w(v);
  vector<TPoro> x = v;

  cout << "******TESTING RESIZE, OPERATOR== AND OPERATOR!=******" << endl;

  if(v == w)
    cout << "true" << endl;

  if(v == x)
    cout << "true" << endl;

  cout << v.size() << endl;
  cout << v << endl;

  v.resize(3);
  cout << v.size() << endl;

  if(v == w)
    cout << "ERROR" << endl;

  if(v == x)
    cout << "ERROR" << endl;

  cout << v << endl;

  v.resize(6);
  cout << v.size() << endl;

  if(v != w)
    cout << "true" << endl;

  if(v != x)
    cout << "true" << endl;

  cout << v << endl;

  v.resize(v.size());

  cout << v.size() << endl;
  cout << v << endl;

}
