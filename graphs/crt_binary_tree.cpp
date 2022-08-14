//
// Created by sachet on 12/8/22.
//

#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vvi;
struct TreeNode{
  int val;
  TreeNode *left{nullptr}, *right{nullptr};
  TreeNode(int x): val(x){}
};

TreeNode* createBinaryTree(vvi &desc) {
  unordered_map<int, TreeNode *> um;
  unordered_set<int> hasprnt;
  for (auto &i: desc) {
    if (!um.count(i[0])) um[i[0]] = new TreeNode(i[0]);
    if (!um.count(i[1])) um[i[1]] = new TreeNode(i[1]);
    if (i[2] == 1) um[i[0]]->left = um[i[1]];
    else um[i[0]]->right = um[i[1]];
    hasprnt.insert(i[1]);
  }
  for (auto &i: desc) {
    if (!hasprnt.count(i[0])) return um[i[0]];
  }
  return nullptr;
}