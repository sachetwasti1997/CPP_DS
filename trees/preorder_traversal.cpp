//
// Created by sachet on 8/8/22.
//
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

struct TreeNode{
  int val;
  TreeNode *left, *right;
};

void traverse(TreeNode *rt, vi &rs){
  if(!rt) return;
  rs.emplace_back(rt->val);
  traverse(rt->left, rs);
  traverse(rt->right, rs);
}

vi preorderTraversal(TreeNode* root) {
  vi res;
  traverse(root, res);
  return res;
}