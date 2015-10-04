#include "mystack.h"
#include <iostream>
using namespace std;

int main () {
  MyStack<int> s;
  s.push(1);
  s.push(2);
  s.push(3);  
  s.print();
  s.pop();
  s.pop();
  s.pop();
  s.pop();  
  
}
