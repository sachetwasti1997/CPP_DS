//
// Created by sachet on 9/8/22.
//
#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
};

bool count (TreeNode *r, int &cnt) {
    if (!r) return true;
    bool left = count(r->left, cnt);
    bool right = count(r->right, cnt);
    if(left && right){
        if (r->left && r->val != r->left->val) return false;
        if (r->right && r->val != r->right->val) return false;
        cnt++;
        return true;
    }
    return false;
}

int countUnivalSubtrees(TreeNode* root) {
    int cnt = 0;
    count(root, cnt);
    return cnt;
}