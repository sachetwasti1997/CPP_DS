//
// Created by sachet on 16/8/22.
//
#include <bits/stdc++.h>
using namespace std;

  typedef vector<int> vi;
  typedef vector<vector<int>> vvi;

  int shortestDistance(vvi &m, vi &s, vi &dst) {
    auto comp = [](vi &v1, vi &v2){ return v1[2] < v2[2];};
    priority_queue<vi, vvi, decltype(comp)> pq(comp);
    pq.push({s[0], s[1], 0});
    vvi dist(m.size(), vi(m[0].size(), INT_MAX));
    vvi dir{{1,0},{0,1},{-1,0},{0,-1}};
    dist[s[0]][s[1]] = 0;
    int R = m.size(), C = m[0].size();
    while (!pq.empty()) {
      vi tmp = pq.top();
      pq.pop();
      if (dist[tmp[0]][tmp[1]] < tmp[2]) continue;
      for (auto &d:dir) {
        int x = tmp[0] + d[0];
        int y = tmp[1] + d[1];
        int cnt = 0;
        while (x >= 0 && y >= 0 && x < R && y < C && m[x][y] == 0) {
          x += d[0];
          y += d[1];
          cnt++;
        }
        x -= d[0], y -= d[1];
        if (dist[tmp[0]][tmp[1]]+cnt < dist[x][y]) {
          dist[x][y] = dist[tmp[0]][tmp[1]]+cnt;
          pq.push({x, y, dist[x][y]});
        }
      }
    }
    return dist[dst[0]][dst[1]] == INT_MAX ? -1 : dist[dst[0]][dst[1]];
  }