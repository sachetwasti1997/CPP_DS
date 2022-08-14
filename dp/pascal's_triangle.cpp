#include<bits/stdc++.h>
using namespace std;
//
// Created by sachet on 7/8/22.
//
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
  vvi generate(int numRows) {
    if(numRows == 1)return {{1}};
    vvi res{{1}, {1,1}};
    for(int i=2; i<numRows; i++){
      int j = 1;
      vi tmp(i+1, 1);
      while(j < i){
        tmp[j] = res[i-1][j-1] + res[i-1][j];
        j++;
      }
      res.emplace_back(tmp);
    }
    return res;
  }