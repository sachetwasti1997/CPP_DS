#include<bits/stdc++.h>
using namespace std;
//
// Created by sachet on 7/8/22.
//
typedef vector<int> vi;
class Solution {
public:
  /**
   * nlogn solution
   * @param n
   * @return
   */
  vi countBits(int n) {
    if (n == 0) return {0};
    vi res{0, 1};
    for (int i = 2; i <= n; i++){
      int c = 0, j = i;
      while(j > 0){
        if(j % 2 == 1) c++;
        j /= 2;
      }
      res.emplace_back(c);
    }
    return res;
  }

  vi countBits2(int n) {
    if (n == 0) return {0};
    if (n == 1) return {0, 1};
    if (n == 2) return {0, 1, 1};
    vi dp{0, 1, 1};
    unordered_set<int> bits;
    int t = 2;
    while (t < n){
      t *= 2;
      bits.insert(t);
    }
    int offset = 2;
    for(int i = 3; i <= n; i++){
      if(bits.count(i)) offset = i;
      dp.emplace_back(1+dp[i - offset]);
    }
    return dp;
  }
};