/*
File: tree.h
Header file for binary search tree
*/
#ifndef _tree_h
#define _tree_h

#include <vector>

class tree{
 public:

  tree();
  tree(std::vector<int>);
  ~tree();
  void print();
  bool findVal(int val);
  void add(int val);
  void balance();

 private:

  struct node{
    int val;
    node* left;
    node* right;
  };
  node* head;
  node* buildBST(std::vector<int>&, int, int);
  void print(node*);
  void deleteTree(node*);
};

#include "tree.cc"
#endif
