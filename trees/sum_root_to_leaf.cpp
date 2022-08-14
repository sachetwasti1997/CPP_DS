//
// Created by sachet on 9/8/22.
//
#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
};

void sum(TreeNode *rt, int &nm, int &sm){
    if (!rt) return;
    if (!rt->left && !rt->right){
        nm = nm*10 + rt->val;
        sm += nm;
        nm /= 10;
        return;
    }
    nm = nm*10+rt->val;
    sum(rt->left, nm, sm);
    sum(rt->right, nm, sm);
    nm /= 10;
}

int sumNumbers(TreeNode* root) {
    int res = 0, nm = 0;
    sum(root, nm, res);
    return res;
}