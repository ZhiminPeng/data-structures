#include <iostream>
#include "myvector.h"
using namespace std;

int main() {
  MyVector<int> v;
  v.add(1);
  v.add(2);
  v.add(3);
  v.insertAt(0, -1);
  v.removeAt(2);
  cout << v[2] << endl;
  v.print();
}
