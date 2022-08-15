//
// Created by sachet on 14/8/22.
//
#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

  typedef vector<int> VI;

  VI largestValues(TreeNode* root) {
    if (!root) return VI{};
    queue<TreeNode *> q;
    VI res;
    q.push(root);
    int sz = 1;
    while (!q.empty()) {
      long maxi = LONG_MIN;
      for (int i=0; i<sz; i++) {
        auto tmp = q.front();
        q.pop();
        if(tmp->val > maxi) maxi = tmp->val;
        if (tmp->left) q.push(tmp->left);
        if (tmp->right) q.push(tmp->right);
      }
      res.emplace_back(maxi);
      sz = q.size();
    }
    return res;
  }

