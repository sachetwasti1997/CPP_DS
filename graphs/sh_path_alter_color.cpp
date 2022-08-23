//
// Created by sachet on 18/8/22.
//
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vp;
typedef unordered_map<int, vector<vi>> umivi;
typedef unordered_set<int> usi;
class Solution {
  public:
  void find(vi &res, umivi &gr, int col, int nd, int dis) {
    res[nd] = dis;
    for(auto &i: gr[nd]){
      int flag = 0;
      if (col != i[1] && (res[i[0]] == -1 || res[i[0]] > dis + 1)) {
        res[i[0]] = dis + 1;
        col = -1 * i[1];
        flag = 1;
      }
      if (col != i[1] && (res[i[0]] == -1 || res[i[0]] > dis + 1)) {
        res[i[0]] = dis + 1;
        col = -1 * i[1];
        flag = 1;
      }
      else if((col == i[1])) res[i[0]] = -1;
      if (flag) find(res, gr, i[1], i[0], res[i[0]]);
    }
  }

  vi shortestAlternatingPaths(int n, vvi &rEd, vvi &bEd) {
    umivi gr;
    for (auto &i: rEd) {
      gr[i[0]].push_back({i[1], -1});
    }
    for (auto &i: bEd) gr[i[0]].push_back({i[1], 1});
    vi res(n, INT_MAX);
    auto t = gr[0];
    res[0] = 0;
    find(res, gr, 0, 0, 0);
    return res;
  }

};