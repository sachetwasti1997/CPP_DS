//
// Created by sachet on 12/8/22.
//
#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> vvi;
typedef unordered_map<int, vector<int>> umiv;

struct TreeNode{
  int val;
  TreeNode *left, *right;
};

int traverse (TreeNode *r, umiv &mp) {
  if (!r) return 0;
  int left = traverse(r->left, mp);
  int right = traverse(r->right, mp);
  int h = max(left, right) + 1;
  mp[h].push_back(r->val);
  return h;
}
  
vvi findLeaves(TreeNode* root) {
  umiv mp;
  int ht = traverse(root, mp);
  vvi res;
  for (int i=1; i<=ht; i++)
    res.emplace_back(mp[i]);
  return res;
}