#include <bits/stdc++.h>
using namespace std;
//
// Created by sachet on 7/8/22.
//
class Solution {
public:
  int tribonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 1;
    vector<long> dp{0L, 1L, 1L};
    for (int i = 3; i <= n; i++){
      dp.emplace_back(dp[i-1] + dp[i-2] + dp[i-3]);
    }
    return dp[dp.size()-1];
  }
};