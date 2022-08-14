//
// Created by sachet on 9/8/22.
//
#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
  int val;
  TreeNode *left, *right;
};

//int rob_wrong (TreeNode* root) {
//  queue<TreeNode *> q;
//  unordered_map<bool, int> sm_map;
//  int sz = 1;
//  bool inx = false;
//  q.push(root);
//  while(!q.empty()){
//    for(int i=0; i<sz; i++) {
//      TreeNode *tmp = q.front();
//      q.pop();
//      sm_map[inx] += tmp->val;
//      if (tmp->left) q.push(tmp->left);
//      if (tmp->right) q.push(tmp->right);
//    }
//    sz = q.size();
//    inx = !inx;
//  }
//  return max(sm_map[true], sm_map[false]);
//}
//
//int maxrob_naive(TreeNode *r, bool rob=true){
//  if (!r) return 0;
//  int frRob = maxrob_naive(r->left, true) + maxrob_naive(r->right, true);
//  int currRob = rob ? r->val + maxrob_naive(r->left, false)
//                        + maxrob_naive(r->right, false): -1;
//  return max(frRob, currRob);
//}
//
//int rob112(TreeNode* root) {
//  return maxrob_naive(root);
//}
class Sol{
  typedef unordered_map<TreeNode*, vector<int>> umTvi;
  int mxRb (TreeNode *r, umTvi &dp, bool rob) {
    if(!r) return 0;
    if (dp.count(r) && dp[r][rob] != -1) return dp[r][rob];
    dp[r] = {-1,-1};
    int frRb = mxRb(r->left, dp, true) +
               mxRb(r->right, dp, true);
    int currRb = rob ? r->val + mxRb(r->left, dp, false) +
                         mxRb(r->right, dp, false):-1;
    return dp[r][rob] = max(frRb, currRb);
  }

  int rob(TreeNode *r){
    umTvi dp;
    return mxRb(r, dp, true);
  }
};
/**
* Line 37: Char 17: error: non-const lvalue reference to type 'Solution::vN' (aka 'vector<NestedInteger>') cannot bind to a value of unrelated type 'NestedInteger'
else sum (i, dpth+1, sm);
          ^
Line 34: Char 16: note: passing argument to parameter 'nL' here
void sum(vN& nL, int dpth, int &sm){
         ^
1 error generated.
*/