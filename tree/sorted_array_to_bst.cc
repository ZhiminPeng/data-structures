#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *helper(vector<int> &num, int begin, int end)
{
  int middle = begin + (end - begin)/2;
  TreeNode * root = new TreeNode(num[middle]);
  if(begin==end) return root;
  root->left = helper(num, begin, middle);
  root->right = helper(num, middle, end);
}

TreeNode *sortedArrayToBST(vector<int> &num)
{
  TreeNode *root;
  if(num.size()==0) return root;
  root = helper(num, 0, num.size());
  return root;
}


int main()
{
  vector<int> num;
  cout<<num.size()<<endl;
  TreeNode *root = sortedArrayToBST(num);
  cout<<root->val;
  return 0;

}
