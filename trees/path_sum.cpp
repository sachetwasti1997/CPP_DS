//
// Created by sachet on 8/8/22.
//
struct TreeNode{
  int val;
  TreeNode *left, *right;
};
bool hasPathSum(TreeNode* root, int t) {
  if (!root) return false;
  if (root -> val == t && !root -> left && !root -> right) return true;
  return hasPathSum(root->left, t-root->val) || hasPathSum(root->right, t-root->val);
}