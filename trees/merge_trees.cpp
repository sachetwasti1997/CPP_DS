#include <bits/stdc++.h>

#include <memory>
using namespace std;
//
// Created by sachet on 29/7/22.
//
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};


//TreeNode * dfs(TreeNode *r1, TreeNode *r2){
//    if(r1 && r2){
//        auto *res = new TreeNode(r1 -> val + r2 -> val);
//        res->left = dfs(r1->left, r2 -> left);
//        res->right = dfs(r1 -> right, r2 -> right);
//        return res;
//    }else{
//        return r1 ? r1 : r2;
//    }
//}

TreeNode * dfs(TreeNode *r1, TreeNode * r2){
    if(r1 && r2){
        auto res = make_unique<TreeNode>(r1 -> val + r2 -> val);
        res -> left = dfs(r1 -> left, r2 -> left);
        res -> right = dfs(r1 -> right, r2 -> right);
        return res.get();
    }else{
        return r1 ? r1 : r2;
    }
}

TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {

    return dfs(root1, root2);

}
