//
// Created by sachet on 14/8/22.
//
#include "TreeNode.h"

bool check(TreeNode *rt, int left, int right) {
  if (!rt) return true;
  bool l = check(rt->left, left, rt->val);
  bool r = check(rt->right, rt->val, right);
  return l && r && rt->val >left && rt->val < right;
}
int count(TreeNode *rt) {
  if (!rt) return 0;
  return 1 + count(rt->left) + count(rt->right);
}
void checkBST(TreeNode *rt, int &cnt) {
  if (!rt) return;
  bool b = check(rt, INT_MIN, INT_MAX);
  if (b) cnt = max(cnt, count(rt));
  checkBST(rt->left, cnt);
  checkBST(rt->right, cnt);
}
int largestBSTSubtree(TreeNode* rt) {
  if (!rt) return 0;
  int cnt = 0;
  checkBST(rt, cnt);
  return cnt;
}