#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define MARKER -1

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int v) : val(v), left(NULL), right(NULL) {}
};

// serialize the tree with preorder traversal
vector<int> serialize(TreeNode* head) {
  vector<int> result;
  if (head == NULL) {
    return result;
  }
  result.push_back(head->val);
  if (head->left == NULL) {
    result.push_back(-1);
  } else {
    vector<int> left = serialize(head->left);
    result.insert(result.end(), left.begin(), left.end());
  }
  if (head->right == NULL) {
    result.push_back(-1);
  } else {
    vector<int> right = serialize(head->right);
    result.insert(result.end(), right.begin(), right.end());
  }
  return result;
}

TreeNode* deserialize(vector<int> v, int& start) {
  if (v.size() == 0 || start >= v.size() || v[start] == MARKER) {
    ++start;
    return NULL;
  }
  TreeNode* head = new TreeNode(v[start]);
  start = start + 1;
  TreeNode* left = deserialize(v, start);
  TreeNode* right = deserialize(v, start);
  head->left = left;
  head->right = right;
  return head;
}


void print(vector<int>& a) {
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

int main() {

  TreeNode* root = new TreeNode(20);
  root->left               = new TreeNode(8);
  root->right              = new TreeNode(22);
  root->left->left         = new TreeNode(4);
  root->left->right        = new TreeNode(12);
  root->left->right->left  = new TreeNode(10);
  root->left->right->right = new TreeNode(14);
  vector<int> v = serialize(root);
  print(v);
  int start = 0;
  TreeNode* temp = deserialize(v, start);
  vector<int> w = serialize(temp);  
  print(w);

}
