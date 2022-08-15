//
// Created by sachet on 14/8/22.
//
#include <bits/stdc++.h>
using namespace std;

int islandPerimeter(vector<vector<int>>& grid) {
  int R = grid.size(), C = grid[0].size();
  int result = 0;
  for (int i=0; i<R; i++) {
    for (int j=0; j<C; j++) {
      if (grid[i][j] == 1){
        result += 4;
        if (i > 0 && grid[i-1][j] == 1) result -= 2;
        if (j > 0 && grid[i][j-1] == 1) result -= 2;
      }
    }
  }
  return result;
}