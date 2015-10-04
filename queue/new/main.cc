#include <iostream>
#include "myqueue.h"
using namespace std;

int main() {
  MyQueue<int> q;
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.dequeue();
  cout << q.size() << endl;
  q.print();
}
