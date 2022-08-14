//
// Created by sachet on 13/8/22.
//
#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
  int val;
  TreeNode *left, *right;
  TreeNode(int x):val(0), left(nullptr), right(nullptr){};
};
typedef vector<TreeNode *> vTN;

vTN gen(int s, int e) {
  if (s > e) return vTN{nullptr};
  vTN res;
  for (int i=s; i<=e; i++) {
    vTN left = gen(s, i-1);
    vTN rght = gen(i+1, e);
    for(TreeNode* l: left){
      for(TreeNode* r: rght){
        auto *nd = new TreeNode(i);
        nd->left = l;
        nd->right = r;
        res.emplace_back(nd);
      }
    }
  }
  return res;
}

vTN generateTrees(int n) {
  return gen(1, n);
}