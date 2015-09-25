#include <iostream>
#include "my_hash_map.h"
#include <string>
using namespace std;

int main()
{
  MyHashMap<int> my_map;
  my_map.add("cat", 1);
  my_map.add("dog", 2);
  my_map.add("car", 3);
  cout<<my_map.get_val("dog")<<endl;
  return 0;
}
