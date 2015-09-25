#include <iostream>       // std::cout
#include <queue>          // std::priority_queue
#include <vector>
using namespace std;
struct cmp
{
  bool operator ()(const int a, const int b)
  {
    return a < b;
  }
};

int main ()
{
  std::priority_queue<int, vector<int>, cmp> mypq;

  mypq.push(30);
  mypq.push(100);
  mypq.push(25);
  mypq.push(40);

  std::cout << "Popping out elements...";
  while (!mypq.empty())
  {
     std::cout << ' ' << mypq.top();
     mypq.pop();
  }
  std::cout << '\n';

  return 0;
}
