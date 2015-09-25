#include <vector>
#include <iostream>
using namespace std;

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x): val(x), left(NULL), right(NULL) {}

}


void bfs(vector<vector<int> >& result, int level, TreeNode* root){
  if(root==NULL) return;
  if(level > result.size() ) result.push_back(vector<int>());
  result[level-1].push_back(root->val);
  bfs(result, level+1, root->left);
  bfs(result, level+1, root->right);
}
vector<vector<int> > levelOrderBottom(TreeNode *root) {
  vector<vector<int> > result;
  bfs(result, 1, root);
  reverse(result.begin(), result.end());
  return result;
}

int main(){
  



}
