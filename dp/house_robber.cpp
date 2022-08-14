//
// Created by sachet on 7/8/22.
//
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int find432(vi &c, vi &dp, int inx){
  if (inx >= c.size()) return 0;
  if (dp[inx] != -1) return dp[inx];
  return dp[inx] = max(c[inx]+ find432(c, dp, inx + 2), find432(c, dp, inx + 1));
}
int rob(vi &nums) {
  vi dp(nums.size()+1, -1);
  return find432(nums, dp, 0);
}