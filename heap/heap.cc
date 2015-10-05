#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;


class minHeap {
  
private:
  vector<int> cache_;
  // heapfy the heap where the two children heaps are valid
  void heapfy(int node);
  int parent(int node);
  int leftChild(int node);
  int rightChild(int node);
  void buildHeap(int node);

public:
  // insert an element to the min heap
  void push(int val);
  // return the min of the heap
  int top();
  // pop the top element
  void pop();
  // size
  int size();
  // check if the minHeap is empty of not
  bool empty();
  // print
  void print();
  // contructor
  minHeap() {};
  minHeap(vector<int>);
  minHeap(int);
  
};


int minHeap::size() {
  return cache_.size();
}

bool minHeap::empty() {
  return cache_.empty();
}

void minHeap::print() {
  for (int i = 0; i < cache_.size(); i++) {
    cout << cache_[i] << " ";
  }
  cout << endl;
}

int minHeap::parent(int node) {
  if (node <= 0) {
    return -1;
  }
  return (node - 1) / 2;
}

int minHeap::leftChild(int node) {
  return (2 * node + 1 >= cache_.size()) ? -1 : (2 * node + 1);
}

int minHeap::rightChild(int node) {
  return (2 * node + 2 >= cache_.size()) ? -1 : (2 * node + 2);  
}

void minHeap::push(int val) {
  cache_.push_back(val);
  int curr = cache_.size() - 1;
  while (parent(curr) != -1 && cache_[parent(curr)] > cache_[curr]) {
    swap(cache_[parent(curr)], cache_[curr]);
    curr = parent(curr);
  }
}

// heapfy the heap where curr.leftChild and curr.rightChild are heap
void minHeap::heapfy(int curr) {
  
  int smaller_child = INT_MIN;
  int left = leftChild(curr);
  int right = rightChild(curr);
  if (left != -1 && cache_[curr] > cache_[left]) {
    smaller_child = left;
  }
  if (right != -1 && cache_[smaller_child] > cache_[right]) {
    smaller_child = right;
  }
  if (smaller_child != INT_MIN) {
    swap(cache_[smaller_child], cache_[curr]);
    heapfy(smaller_child);
  }
  return;
}

void minHeap::pop() {
  if (cache_.size() == 0) {
    cout << "The heap is empty" << endl;
    return;
  }
  swap(cache_[0], cache_[cache_.size() - 1]);
  cache_.pop_back();
  heapfy(0);
}

// can do it with a for loop, without using recursion
// see the reference
// http://theoryofprogramming.com/2014/12/28/binary-heaps/
void minHeap::buildHeap(int node) {
  int left_child = leftChild(node);
  int right_child = rightChild(node);
  if (left_child != -1) {
    buildHeap(left_child);
  }
  if (right_child != -1) {
    buildHeap(right_child);
  }
  heapfy(node);
  return;
}

minHeap::minHeap(vector<int> v) {
  cache_ = v;
  buildHeap(0);
}

minHeap::minHeap(int val) {
  cache_.push_back(val);
}



int main() {


  // vector<int> v = {4, 3, 2, 1, 0};
  //  minHeap m(v);
  minHeap m;
  m.push(0);
  m.push(4);
  m.push(1);
  m.push(5);
  m.push(6);  
  m.push(2);
  m.push(7);    
  m.print();
  m.pop();
  m.print();
  return 0;
}
