//
// Created by sachet on 14/8/22.
//
#include "TreeNode.h"
#include <bits/stdc++.h>

void find(TreeNode *rt, int curr, int &mdp, long &lft) {
  if (!rt) return;
  find(rt->left, curr+1, mdp, lft);
  if (lft == LONG_MAX || mdp < curr) {
    mdp = curr;
    lft = rt->val;
  }
  find(rt->right, curr+1, mdp, lft);
}

int findBottomLeftValue(TreeNode* rt) {
  if (!rt->left and !rt->right) return rt->val;
  int mdp = 0;
  long lft = LONG_MAX;
  if (!rt->left) find(rt->right, 0, mdp, lft);
  else find(rt, 0, mdp, lft);
  return (int)lft;
}
