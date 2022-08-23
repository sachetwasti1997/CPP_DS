//
// Created by sachet on 16/8/22.
//
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> Vi;
typedef vector<Vi> Vvi;
typedef unordered_map<int, Vi> UmVi;

int find(UmVi &gr, Vi &res, int i, Vi &qt) {
  if (res[i] >= 0) return res[i];
  res[i] = i;
  for (auto &j: gr[i])
    if (qt[res[i]] > qt[find(gr, res, j, qt)]) res[i] = res[j];
  return res[i];
}

Vi loudAndRich(Vvi &rchr, Vi &qt) {
  int n = qt.size();
  UmVi gr(n);
  for (auto &i: rchr) gr[i[1]].emplace_back(i[0]);
  Vi res(n, -1);
  for (int i=0; i<n; i++) find(gr, res, i, qt);
  return res;
}

int main() {
  Vvi rchr{{1,0},{2,1},{3,1},{3,7},{4,3},{5,3},{6,3}};
  Vi qt{3,2,5,4,6,1,7,0};
  auto s = loudAndRich(rchr, qt);
  for (auto &i: s) cout<<i<<" ";
}
