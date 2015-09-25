#include <iostream>
#include "myqueue.h"
using namespace std;

int main()
{
  MyQueue<int> v;
  v.enqueue(1);
  v.enqueue(2);
  v.enqueue(3);
  v.dequeue();
  v.dequeue();
  v.dequeue();
  v.dequeue();
  v.print();

  return 0;
}
