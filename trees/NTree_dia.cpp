//
// Created by sachet on 13/8/22.
//
#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vvi;
typedef unordered_set<int> usi;

int calc(vvi &tr, int nd, int &d, usi &visit) {
  if (tr[nd].empty()) return 0;
  visit.insert(nd);
  int m1 = 0;
  for(int i: tr[nd]){
    if(!visit.count(i)){
      int res = 1+calc(tr, i, d, visit);
      d = max(d, m1+res);
      m1 = max(m1, res);
    }
  }
  return m1;
}

int treeDiameter(vvi &ed) {
  vvi tre(ed.size()+1);
  usi v(ed.size()+1);
  for (auto &i: ed) {
    tre[i[0]].emplace_back(i[1]);
  }
  int dis = 0;
  calc(tre, 0, dis, v);
  return dis;
}