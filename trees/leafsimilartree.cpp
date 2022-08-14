#include<bits/stdc++.h>
using namespace std;
//
// Created by sachet on 29/7/22.
//
//struct TreeNode{
//    int val; TreeNode *left; TreeNode *right;
//    TreeNode(int val): val(0), left(nullptr), right(nullptr){}
//};

class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
};

//void dfsHelper(TreeNode * r, string & s){
//    if(r == nullptr)return;
//    if(r -> right == nullptr && r -> left == nullptr)s.append(to_string(r->val));
//    dfsHelper(r -> left, s);
//    dfsHelper(r -> right, s);
//}
//
//bool leafSimilar(TreeNode* root1, TreeNode* root2) {
//    string s1, s2;
//    dfsHelper(root1, s1);
//    dfsHelper(root2, s2);
//    return s1 == s2;
//}

void dfs(TreeNode * r, vector<int> &v){
    if (r == nullptr)return;
    if (!r -> left && !r -> right)v.push_back(r->val);
    dfs(r->left, v);
    dfs(r -> right, v);
}

bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> v1, v2;
    dfs(root1, v1);
    dfs(root2, v2);
    return v1 == v2;
}


