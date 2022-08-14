//
// Created by sachet on 9/8/22.
//
#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
};

void successor(TreeNode* r, TreeNode *p, TreeNode *&res){
    if (!r) return;
    if (r->val <= p->val) successor(r->right, p, res);
    else if(r->val > p->val) {
        if (!res || res->val > r->val)res = r;
        successor(r->left, p, res);
    }
}
TreeNode* inorderSuccessor(TreeNode* r, TreeNode* p) {
    TreeNode *res{nullptr};
    successor(r, p, res);
    return res;
}