//
// Created by sachet on 13/8/22.
//
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int find(int n, vi &dp) {
  if (n == 0) return 1;
  if (n == 1) return 1;
  if (dp[n] != -1) return dp[n];
  int res = 0;
  for (int i=1; i<=n; i++) {
    res += find(i-1, dp) * find(n-i, dp);
  }
  return dp[n] = res;
}

int numTrees(int n) {
  vi dp(n+1, -1);
  return find(n, dp);
}