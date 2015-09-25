#include "tree.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int arr[5] = {1,2,3,4,5};
  vector<int> v(arr, arr+5);
  for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
  cout<<endl;

  tree t(v);

  t.print();
  return 0;

}
