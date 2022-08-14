//
// Created by sachet on 7/8/22.
//
#include<bits/stdc++.h>
using namespace std;
typedef string str;
typedef vector<vector<int>> vvi;
class Solution {
public:
  int lcs(str s, str t, int i, int j, vvi &dp){
    if (i == s.size() || j == t.size()) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if (s[i] == t[j]) return dp[i][j] = 1 + lcs(s, t, i + 1, j + 1, dp);
    return dp[i][j] = max(lcs(s, t, i+1, j, dp) , lcs(s, t, i, j+1, dp));
  }
  bool isSubsequence(str s, str t) {
    vvi dp(s.size()+1, vector<int>(t.size(), -1));
    int r = lcs(s, t, 0, 0, dp);
    return r == s.size();
  }
  bool isSubsequence2(string s, string t) {
    int j = 0;
    for (int i=0; i<t.size(); i++){
      if(t[i] == s[j]) j++;
    }
    return j == s.size();
  }
};
