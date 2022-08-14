//
// Created by sachet on 10/8/22.
//
#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> vvi;
typedef unordered_map<int, int> umii;

bool bfs(vvi &g, int nod, umii &mp){
  mp[nod] = -1;
  queue <int> q;
  q.push(nod);
  while (!q.empty()) {
    int t = q.front(); q.pop();
    for (auto &i: g[t]) {
      if (mp[i] == 0) q.push(i);
      if (mp[i] == mp[t]) return false;
      mp[i] = -1 * mp[t];
    }
  }
  return true;
}

bool isBipartite(vvi &g) {
  umii mp;
  for (int i=0; i<g.size(); i++)
    if (mp[i] == 0 && !bfs(g, i, mp)) return false;
  return true;
}