#include <iostream>
#include "mystack.h"
using namespace std;

int main()
{
  MyStack<int> v;
  v.push(1);
  v.push(2);
  v.push(3);
  v.pop();
  v.print();
  cout<<v.top()<<endl;
  return 0;
}
