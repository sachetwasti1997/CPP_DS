//
// Created by sachet on 14/8/22.
//

#include "TreeNode.h"
#include <bits/stdc++.h>
using namespace std;

void updown(TreeNode *rt, TreeNode *prnt, TreeNode *&hd){
  if (!rt) return;
  updown(rt->left, rt, hd);
  if (!hd) hd = rt;
  rt->left = prnt?prnt->right:nullptr;
  rt->right = prnt;
}

TreeNode* upsideDownBinaryTree(TreeNode* root) {
  if (!root || !root->left) return root;
  TreeNode *hd{nullptr};
  updown(root, nullptr, hd);
  return hd;
}
