#include<bits/stdc++.h>
using namespace std;
//
// Created by sachet on 30/7/22.
//
typedef vector<vector<int>> VVI;
typedef vector<int> VI;
class Solution {
  public:
  struct hash{
    size_t operator()(VI const &v) const {
      return v[0] ^ v[1];
    }
  };
  bool hasPath(VVI &m, VI &s, VI &dst) {
    int R = m.size(), C = m[0].size();
    VVI dir = {{1,0},{0,1},{-1,0},{0,-1}};
    unordered_set<VI, hash> us;
    queue<VI> q;
    q.push(s);
    us.insert(s);
    while (!q.empty()) {
      auto tmp = q.front();
      if (tmp[0] == dst[0] && tmp[1] == dst[1]) return true;
      q.pop();
      for (auto &d: dir) {
        int x = d[0] + tmp[0];
        int y = d[1] + tmp[1];
        while (x >= 0 && y >= 0 && x < R && y < C && m[x][y] == 0) {
          x += d[0];
          y += d[1];
        }
        x -= d[0], y -= d[1];
        if (!us.count({x, y})) {
          us.insert({x,y});
          q.push({x,y});
        }
      }
    }
    return false;
  }
};