//
// Created by sachet on 13/8/22.
//
struct TreeNode{
  int val;
  TreeNode *left, *right;
};
void sumleft(TreeNode * root, int pos, int &sum) {
  if(!root) return;
  if(!root->left and !root->right and pos) sum += root->val;
  sumleft(root->left, 1, sum);
  sumleft(root->right, 0, sum);
}

int sumOfLeftLeaves(TreeNode* root) {
  int sum = 0;
  sumleft(root, 0, sum);
  return sum;
}