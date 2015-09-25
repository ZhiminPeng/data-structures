#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode (int v) : val(v), left(NULL), right(NULL) {}
};

// find a target in a binary search tree
TreeNode* search(TreeNode* root, int target) {
  if (root == NULL) {
    return NULL;
  }
  if (root->val == target) {
    return root;
  } else if (target < root->val) {
    return search(root->left, target);
  } else {
    return search(root->right, target);
  }
}


// insert a target to a BST
TreeNode* insert(TreeNode* root, int target) {
  if (root == NULL) {
    TreeNode* temp = new TreeNode(target);
    return temp;
  }
  if (target <= root->val) {
    TreeNode* left = insert(root->left, target);
    root->left = left;
  } else {
    TreeNode* right = insert(root->right, target);
    root->right = right;
  }
  return root;
}



// inorder travelsal recursive implementation
vector<int> inorderTravel(TreeNode* root) {
  vector<int> result;
  if (root == NULL) {
    return result;
  }
  vector<int> left = inorderTravel(root->left);
  vector<int> right = inorderTravel(root->right);
  result.insert(result.end(), left.begin(), left.end());
  result.push_back(root->val);
  result.insert(result.end(), right.begin(), right.end());
}


TreeNode* findMin(TreeNode* root) {
  TreeNode* curr = root;
  while (root->left) {
    curr = curr->left;
  }
  return curr;
}

TreeNode* remove(TreeNode* root, int target) {

  if (root == NULL) {
    return NULL;
  }

  if (root->val > target) {
    root->left = remove(root->left, target);
  } else if (root->val < target){
    root->right = remove(root->right, target);
  } else {
    if (root->left == NULL) {
      TreeNode* temp = root->right;
      delete[] root;
      return temp;
    } else if (root->right == NULL) {
      TreeNode* temp = root->left;
      delete[] root;
      return temp;
    } else {
      TreeNode* temp = findMin(root->right);
      root->val = temp->val;
      root->right = remove(root->right, temp->val);
    }
  }
  return root;
}



// inorder travelsal non recursive implementation



// dfs recursive


// dfs nonrecursive


// bfs recursive


// bfs nonrecursive


void print(vector<int>& v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}


int main() {
  
  TreeNode* root = new TreeNode(5);
  root->left = new TreeNode(3);
  root->right = new TreeNode(7);

  root = insert(root, 8);
  root = insert(root, 1);
  root = insert(root, 2);
  root = insert(root, 4);      

  TreeNode* temp = search(root, 8);
  vector<int> order = inorderTravel(root);
  print(order);  
  root = remove(root, 2);
  root = remove(root, 5);
  vector<int> new_order = inorderTravel(root);
  print(new_order);
  
  return 0;
}
