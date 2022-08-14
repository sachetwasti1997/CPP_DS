//
// Created by sachet on 10/8/22.
//
#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> vvi;
typedef unordered_map<int, int> umii;
typedef unordered_map<int, vector<int>> umiv;

bool bfs(umiv &gr, umii &mp, int nod){
  mp[nod] = -1;
  queue <int> q;
  q.push(nod);
  while (!q.empty()) {
    int tmp = q.front();q.pop();
    for (auto &i : gr[tmp]) {
      if (!mp.count(i)) q.push(i);
      if (mp[i] == mp[tmp]) return false;
      mp[i] = -1 * mp[tmp];
    }
  }
  return true;
}

bool possibleBipartition(int n, vvi &gr) {
  umii mp(n);
  umiv g(2*n);
  for (auto &i: gr) {
    g[i[0]].push_back(i[1]);
    g[i[1]].push_back(i[0]);
  }
  for (int i=0; i<gr.size(); i++)
    if (mp[i] == 0 && !bfs(g, mp, i)) return false;
  return true;
}
typedef unordered_set<int> usi;

bool dfs(int nod, umiv &g, usi &v, umii &mp){
  v.insert(nod);
  if (!mp[nod]) mp[nod] = -1;
  for (auto &i: g[nod]){
    if (mp[i] == mp[nod]) return false;
    mp[i] = -1 * mp[nod];
    if (!v.count(i) && !dfs(i, g, v, mp)) return false;
  }
  return true;
}

bool possibleBipartition2(int n, vvi &gr) {
  umiv g(n);
  usi v(n);
  umii mp(n);
  for (auto &i: gr){
    g[i[0]].emplace_back(i[1]);
    g[i[1]].emplace_back(i[0]);
  }
  for (int i=0; i<n; i++)
    if(!v.count(i) && !dfs(i, g, v, mp)) return false;
  return true;
}