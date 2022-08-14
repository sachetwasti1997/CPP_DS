//
// Created by sachet on 12/8/22.
//
/*
Meat of the problem here is to find the number of connected components in the graph.
Now each of the node in one group of connected components will form an unreachable pair with each node of another group, given the groups are not connected.
So after calculating the connected components we can perform simple multiplication and addition to find the result.
 * */
#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> vvi;
typedef long long ll;
typedef unordered_map<int, int> umii;
typedef unordered_set<int> usi;

void reach (vvi &g, usi &us, int &c, int node) {
  us.insert(node);
  c++;
  for (auto &i: g[node]) {
    if (!us.count(i)) {
      reach(g, us, c, i);
    }
  }
}

ll countPairs(int n, vvi &edges) {
  vvi g(n);
  usi us(n);
  umii cnt(n);
  for (auto &i: edges) {
    g[i[0]].push_back(i[1]);
    g[i[1]].push_back(i[0]);
  }
  ll rn = 0, res = 0;
  for (int i = 0; i < n; i++) {
    if (!us.count(i)) {
      int c = 0;
      reach (g, us, c, i);
      cout<<i<<":"<<c<<endl;
      res += rn*c;
      rn += c;
    }
  }
  return res;
}