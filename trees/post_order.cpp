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

void traverse223(TreeNode *rt, vi &rs){
  if (!rt) return;
  traverse223(rt->left, rs);
  traverse223(rt->right, rs);
  rs.emplace_back(rt->val);
}

vi postorderTraversal(TreeNode* root) {
  vi res;
  traverse223(root, res);
  return res;
}

int mainldrt(){
  double d = 2.33345;
  int t = 3;
  double f = t - d;
  cout<<f;
}