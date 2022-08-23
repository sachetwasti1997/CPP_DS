//
// Created by sachet on 16/8/22.
//
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef unordered_map<int, vector<int>> umiv;

class Solution {
  public:

  static vi loudAndRichwe(vvi &rchr, vi &qt) {
    unsigned int n = qt.size();
    unordered_set<int> us;
    umiv gr(qt.size());
    for (auto &i: rchr) gr[i[1]].push_back(i[0]);
    queue<int> q;
    vi res;
    for (int i=0; i<n; i++) {
      int r = i;
      q.push(i);
      while (!q.empty()) {
        int tmp = q.front();
        q.pop();
        us.insert(tmp);
        for (auto &t: gr[tmp]) {
          if (qt[t] < qt[r]) r = t;
          if (us.count(t))q.push(t);
        }
      }
      res.push_back(r);
    }
    return res;
  }
};