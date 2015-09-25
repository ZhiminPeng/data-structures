#include <vector>
#include <iostream>
using namespace std;

int main(){
  vector<int> a(4);
  vector<vector<int> > b;
  a.push_back(1);
  cout<<a.capacity()<<endl;
  cout<<a.max_size()<<endl;
  cout<<b.max_size()<<endl;
  a.pop_back();
 
  cout<<a.capacity()<<endl;
  a.clear();
  cout<<a.capacity()<<endl;
}
