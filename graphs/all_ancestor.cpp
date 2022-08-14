//
// Created by sachet on 12/8/22.
//
/**
 * First reverse edges of all nodes
 * Then perform dfs on the graph so formed, and go on inserting the parents
 */
#include <bits/stdc++.h>
using namespace std;

typedef vector<set<int>> vsi;
typedef vector<vector<int>> vvi;
typedef unordered_set<int> usi;

void dfs(int nd, vvi &g, usi &st, vsi &res) {
  st.insert(nd);
  for (auto &i: g[nd]) {
    if (!st.count(i)) dfs(i, g, st, res);
    if (res[i].size() > 0) res[nd].insert(res[i].begin(), res[i].end());
    res[nd].insert(i);
  }
}

vvi getAncestors(int n, vvi &e) {
  vector<vector<int>> g(n);
  for (auto &i: e){
    g[i[1]].push_back(i[0]);
  }
  vsi res(n);
  usi st(n);
  for (int i=0; i<n; i++)
    if(!st.count(i))
      dfs(i, g, st, res);
  vvi rres(n);
  int f = 0;
  for (auto &i: res) {
    rres[f++].assign(i.begin(), i.end());
  }
  return rres;
}