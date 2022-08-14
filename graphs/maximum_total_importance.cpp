//
// Created by sachet on 12/8/22.
//
/**
The main crux of the algorithm lies in finding the degree of each node.
After that we can sort nodes according to degrees, and find sum.
Sorting by degree of each node, allows to correctly assign values to each of them to get maximum sum.
 */
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int val;
  int deg;
  int num;
  Node *left;
  Node():val(0),deg(0),num(0){}
};

long long maximumImportance(int n, vector<vector<int>> &rds) {
  vector<Node> v(n, Node{});
  for (int i=0; i<rds.size(); i++) {
    v[rds[i][0]].val = rds[i][0];
    v[rds[i][0]].deg++;
    v[rds[i][1]].val = rds[i][1];
    v[rds[i][1]].deg++;
  }
  std::sort(v.begin(), v.end(),[](Node &i1, Node &i2){return i1.deg < i2.deg;});
  int k = 1;
  for (auto &i: v) {
    i.num = k++;
  }
  unordered_map<int, int> um;
  for (auto &i: v){
    um[i.val] = i.num;
  }
  int res = 0;
  for (auto &i: rds){
    res += (um[i[0]]+um[i[1]]);
  }
  return res;
}