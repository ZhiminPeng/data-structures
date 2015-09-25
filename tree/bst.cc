#include <iostream>
using namespace std;

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

void insert(TreeNode*& root, int val){
  if(root==NULL){
    root = new TreeNode(val);
    return;
  }
  if(val < root->val){
    insert(root->left, val);
  }else{
    insert(root->right, val);
  }

}


TreeNode* find_min(TreeNode* root){
  TreeNode* curr = root;
  while(curr->left != NULL){
    curr = curr->left;
  }
  return curr;
}

TreeNode* delete_node(TreeNode* root, int val){
  if(root == NULL){
    return root;
  }
  if(val < root->val){
    root->left = delete_node(root->left, val);
  }else if(val > root->val){
    root->right = delete_node(root->right, val);
  }else{
    if(root->left==NULL){
      TreeNode* temp = root->right;
      delete[] root;
      return temp;
    }else if(root->right == NULL){
      TreeNode* temp = root->left;
      delete[] root;
      return temp;
    }else{
      TreeNode* curr = find_min(root->right);
      root->val = curr->val;
      root->right = delete_node(root->right, curr->val);
    }
  }
  return root;
}

void print_inorder(TreeNode* root){
  if(root==NULL){
    return;
  }
  print_inorder(root->left);
  cout<<root->val <<" ";
  print_inorder(root->right);  
}

int main(){
  TreeNode* root = new TreeNode(5);
  insert(root, 3);
  insert(root, 2);      
  insert(root, 4);  
  insert(root, 7);
  insert(root, 6);
  insert(root, 8);
  print_inorder(root);
  cout<<endl;
  delete_node(root, 2);
  print_inorder(root);  

  cout<<endl;
  delete_node(root, 3);
  print_inorder(root);  

  cout<<endl;
  delete_node(root, 5);
  print_inorder(root);  

  cout<<endl;

  return 0;
}
