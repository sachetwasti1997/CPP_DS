//
// Created by sachet on 8/8/22.
//
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int find(vi &n, vi &dp, int inx, int sz){
  if (inx >= sz) return 0;
  if (dp[inx] != -1) return dp[inx];
  return dp[inx] = max(n[inx] + find(n, dp, inx+2, sz), find(n, dp, inx+1, sz));
}

int rob2(vi &n) {
  if (n.size() == 1) return n[0];
  vi dp(n.size()+1, -1);
  int m1 = find(n, dp, 0, n.size() - 1);
  dp = vi(n.size()+1, -1);
  int m2 = find(n, dp, 1, n.size());
  return max(m1, m2);
}