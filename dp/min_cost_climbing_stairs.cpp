//
// Created by sachet on 7/8/22.
//
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int find(vi &c, vi &dp, int inx){
  if (inx >= c.size()) return 0;
  if (dp[inx] != -1) return dp[inx];
  return dp[inx] = c[inx] + min(find(c, dp, inx + 1), find(c, dp, inx + 2));
}

int minCostClimbingStairs(vi& c) {
  vi dp(c.size()+1, -1);
  find(c, dp, 0);
  return min(dp[0], dp[1]);
}