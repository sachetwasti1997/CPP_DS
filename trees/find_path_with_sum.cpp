#include <bits/stdc++.h>
using namespace std;
//
// Created by sachet on 8/8/22.
//
typedef vector<vector<int>> vvi;
typedef vector<int> vi;

struct TreeNode{
  int val;
  TreeNode *left, *right;
};

void sum(TreeNode *rt, int sm, vvi &rs, vi &tmp){
  if (!rt) return;
  if (rt -> val == sm && !rt -> left && !rt -> right) {
    tmp.emplace_back(rt -> val);
    rs.push_back(tmp);
    tmp.erase(tmp.end()-1);
    return;
  }
  tmp.emplace_back(rt -> val);
  sum(rt -> left, sm - rt -> val, rs, tmp);
  sum(rt -> right, sm - rt->val, rs, tmp);
  tmp.erase(tmp.end() - 1);
}

vvi pathSum(TreeNode* root, int sm) {
  vvi res;
  vi tmp;
  sum(root, sm, res, tmp);
  return res;
}