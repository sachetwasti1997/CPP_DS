//
// Created by sachet on 15/8/22.
//
#include <bits/stdc++.h>
using namespace std;

typedef vector<double> VD;
typedef vector<vector<string>> VVS;
typedef unordered_map<string, double> UMSD;
typedef unordered_map<string, UMSD> UMSUM;
typedef unordered_set<string> USS;

void dfs(string s, string t, UMSUM &gr, double &res, USS &vst, bool &flg) {
  if (s == t) {
    flg = true;
    return;
  }
  if (gr[s].count(t)) {
    res *= gr[s][t];
    flg = true;
    return;
  }
  vst.insert(s);
  for (auto &i: gr[s]) {
    if (!vst.count(i.first)) {
      res *= i.second;
      dfs(i.first, t, gr, res, vst, flg);
    }
  }
}

VD calcEquation(VVS& eqs, VD& vls, VVS &qry) {
  UMSUM gr(2*eqs.size());
  int j = 0;
  for (auto &i: eqs) {
    gr[i[0]][i[1]] = vls[j];
    gr[i[1]][i[0]] = 1 / vls[j];
    j++;
  }
  for (auto &i: gr){
    cout<<i.first<<" -> ";
    for (auto j: i.second) {
      cout<<j.first<<" : "<<j.second<<", ";
    }
    cout<<endl;
  }
  VD res;
  for (auto &i: qry) {
    double ret = 0;
    if (!gr.count(i[0])) ret = -1;
    else if (i[0] == i[1]) ret = 1;
    else {
      USS vst;
      bool flg = false;
      double res = 1;
      dfs(i[0], i[1], gr, res, vst, flg);
      if (flg) ret = res;
      else ret = -1;
    }
    res.emplace_back(ret);
  }
  return res;
}

int maghin() {
  VVS eq{{"a","b"}};
  VD vls{0.5};
  VVS q{{"a","b"},{"b","a"},{"a","c"},{"x","y"}};
  auto res = calcEquation(eq, vls, q);
  for (auto &t: res){
    cout<<t<<" ";
  }
}