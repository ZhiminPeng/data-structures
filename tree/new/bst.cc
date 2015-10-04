// binary search tree header file
#include <stack>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define MARKER -99

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode (int v): val(v), left(nullptr), right(nullptr) {}
};


TreeNode* search(TreeNode* root, int target) {
  if (root == nullptr) {
    return nullptr;
  }

  if (root->val == target) {
    return root;
  } else if (root->val < target) {
    return search(root->right, target);
  } else {
    return search(root->left, target);
  }
}


TreeNode* insert(TreeNode* root, int target) {
  if (root == nullptr) {
    TreeNode* temp = new TreeNode(target);
    return temp;
  }
  if (root->val < target) {
    TreeNode* right = insert(root->right, target);
    root->right = right;
  } else {
    TreeNode* left = insert(root->left, target);
    root->left = left;

  }
  return root;
}


TreeNode* findMin(TreeNode* root) {
  if (root == nullptr) {
    return root;
  }
  while (root->left) {
    root = root->left;
  }
  return root;
}


TreeNode* remove(TreeNode* root, int target) {

  if (root == nullptr) {
    return nullptr;
  }

  if (root->val < target) {
    TreeNode* right = remove(root->right, target);
    root->right = right;
  } else if (root->val > target) {
    TreeNode* left = remove(root->left, target);
    root->left = left;
  } else {

    if (root->left == nullptr) {
      return root->right;
    } else if (root->right == nullptr) {
      return root->left;
    } else {
      TreeNode* min_node = findMin(root->right);
      root->val = min_node->val;
      TreeNode* right = remove(root->right, min_node->val);
      root->right = right;
    }
  }
  return root;
}

// inorder traversal iterative implementation
vector<int> inorderTravel(TreeNode* root) {
  vector<int> result;
  stack<TreeNode*> s;
  TreeNode* p = root;
  while (!s.empty() || p) {
    if (p != nullptr) {
      s.push(p);
      p = p->left;
    } else {
      p = s.top();
      s.pop();
      result.push_back(p->val);
      p = p->right;
    }
  }
  return result;
}

void print(vector<int>& v) {

  for (auto i : v) {
    cout << i << " ";
  }
  cout << endl;
}

// serialize a tree with preorder traversal
vector<int> serialize(TreeNode* root) {

  vector<int> result;
  if (!root) {
    return result;
  }
  result.push_back(root->val);
  if (!root->left) {
    result.push_back(MARKER);
  } else {
    vector<int> left = serialize(root->left);
    result.insert(result.end(), left.begin(), left.end());
  }
  if (!root->right) {
    result.push_back(MARKER);
  } else {
    vector<int> right = serialize(root->right);
    result.insert(result.end(), right.begin(), right.end());
  }
  return result;
}

// deserialize a tree with preorder traversal
TreeNode* deserialize(vector<int>& v, int& start) {

  if (v.size() == 0 || start >= v.size() || v[start] == MARKER) {
    ++start;
    return nullptr;
  }
  TreeNode* root = new TreeNode(v[start]);
  ++start;
  TreeNode* left = deserialize(v, start);
  TreeNode* right = deserialize(v, start);
  root->left = left, root->right = right;
  return root;
}


int main() {
  
  TreeNode* root = new TreeNode(5);
  root->left = new TreeNode(3);
  // root->right = new TreeNode(7);
  /*
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
  */
  vector<int> v = serialize(root);
  print(v);
  int start = 0;
  TreeNode* temp = deserialize(v, start);
  vector<int> fo = serialize(temp);
  print(fo);
  
  return 0;
}
