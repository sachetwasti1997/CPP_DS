//
// Created by sachet on 7/8/22.
//
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
class Solution {
public:
  int ways(int n, vi &dp){
    if (n <= 1) return 1;
    if (dp[n] != -1) return dp[n];
    return dp[n] = ways(n-1, dp) + ways(n-2, dp);
  }
  int climbStairs(int n) {
    vi dp(n+1, -1);
    return ways(n, dp);
  }
};