//
// Created by sachet on 14/8/22.
//
#include <bits/stdc++.h>
using namespace std;

  typedef pair<int, int> PII;
  typedef vector<vector<int>> VII;

  struct prhsh{
    bool operator()(PII const &p1) const {
      return p1.first ^ p1.second;
    }
  };
  typedef unordered_set<PII, prhsh> USPII;
  typedef vector<int> VI;

  int dfs(int i, int j, VII &g, VII &dir, int R, int C, USPII &us) {
    if (i >= 0 && j >= 0 && i < R && j < C && !us.count({i,j}) && g[i][j] == 1) {
      us.insert({i, j});
      int res = 0;
      if (i - 1 < 0 || g[i-1][j] != 1) res += 1;
      if (i + 1 == R || g[i+1][j] != 1) res += 1;
      if (j-1 < 0 || g[i][j-1] != 1) res += 1;
      if (j+1 == C || g[i][j+1] != 1) res += 1;
      for (auto &d: dir) res += dfs(i+d[0], j+d[1], g, dir, R, C, us);
      return res;
    }
    return 0;
  }

  int islandPerimeter(VII &g) {
    VII dir = {{1,0},{0,1},{-1,0},{0,-1}};
    USPII us;
    int si = -1, sj = -1, R = g.size(), C = g[0].size();
    for (int i=0; i<R; i++) {
      for (int j=0; j<C; j++) {
        if (g[i][j] == 1) {
          si = i; sj = j;
          break;
        }
      }
    }
    return dfs(si, sj, g, dir, R, C, us);
  }