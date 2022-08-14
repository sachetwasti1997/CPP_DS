//
// Created by sachet on 11/8/22.
//
#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<vector<bool>> vvb;
void mark(int i, int j, vector<int> sz, int prev, vvb &ocn, vvi &dir, vvi &h) {
  if (i >=0 && j >= 0 && i < sz[0] && j < sz[1] && prev <= h[i][j] && !ocn[i][j]) {
    ocn[i][j] = true;
    for (auto &d: dir) mark(i+d[0], j+d[1], sz, h[i][j], ocn, dir, h);
  }
}

vvi pacificAtlantic(vvi &h) {
  int R = h.size(), C = h[0].size();
  vector<int> sz{R, C};
  vvb pacific(sz[0], vector<bool>(sz[1], false));
  vvb atlantic(sz[0], vector<bool>(sz[1], false));
  vvi dir{{1,0},{0,1},{-1,0},{0,-1}};
  for (int i=0; i < sz[0]; i++) {
    mark(i, 0, sz, -1, pacific, dir, h);
    mark(i, sz[1]-1, sz, -1, atlantic, dir, h);
  }
  for (int i=0; i < sz[1]; i++) {
    mark(0, i, sz, -1, pacific, dir, h);
    mark(sz[0]-1, i, sz, -1, atlantic, dir, h);
  }
  vvi res;
  for (int i=0; i < sz[0]; i++){
    for (int j=0; j < sz[1]; j++){
      if (pacific[i][j] && atlantic[i][j]) res.push_back({i,j});
    }
  }
  return res;
}