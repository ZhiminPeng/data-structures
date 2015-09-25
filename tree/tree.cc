/*
File: tree.cc
Implementation for tree data structure
*/


#include <iostream>
#include <vector>

tree::tree()
{
  head = NULL;
}
//create a tree based on a sorted vector of int
tree::tree(std::vector<int> v)
{
  head = buildBST(v, 0, v.size());
}

// helper function for building a tree based on a sorted vector of int 
tree::node* tree::buildBST(std::vector<int> &v, int begin, int end)
{
  if(begin>=end) return NULL;
  int middle = begin + (end - begin)/2;
  node* my_head = new node;
  my_head->val = v[middle];
  my_head->left = buildBST(v, begin, middle);
  my_head->right = buildBST(v, middle+1, end);
  return my_head;
}


tree::~tree()
{
  //use post order traversal to free all of the nodes
  deleteTree(head);
}

// helper function for removing nodes
void tree::deleteTree(node* my_head)
{
  // post order traversal for deleting a tree
  if(my_head!=NULL){
    deleteTree(my_head->left);
    deleteTree(my_head->right);
    delete my_head;
  }
}

void tree::print(node* my_head)
{
  if(my_head!=NULL){
    print(my_head->left);
    std::cout<<my_head->val<<" ";
    print(my_head->right);
  }
}

void tree::print(){
  print(head);
  std::cout<<std::endl;
}
