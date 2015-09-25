#include <iostream>
#include "myvector.h"
using namespace std;

int main()
{
  MyVector<int> v;
  v.add(1);
  v.add(2);
  v.add(2);
  v.add(2);
  v.insertAt(1, 3);
  v.print();
  return 0;
}
