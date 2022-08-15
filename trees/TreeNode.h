//
// Created by sachet on 14/8/22.
//

#ifndef DATA_STRUCTURES_TREENODE_H
#define DATA_STRUCTURES_TREENODE_H

struct TreeNode{
  int val;
  TreeNode *left, *right;
  TreeNode(int x): val(x), left(nullptr), right(nullptr){};
};

#endif//DATA_STRUCTURES_TREENODE_H
