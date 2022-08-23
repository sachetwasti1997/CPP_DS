//
// Created by sachet on 13/8/22.
//
#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vvi;
struct Node2 {
  int val;
  Node2 *left, *right;
  explicit Node2(int x): val(x), left{nullptr}, right{nullptr}{};
  ~Node2(){delete left, delete right;}
};
int calc(Node2 *rt, int &dia) {
  if (!rt) return 0;
  int left = calc(rt->left, dia);
  int right = calc(rt->right, dia);
  int ht = 1 + max(left, right);
  int tmp = max(ht, 1+left+right);
  dia = max(dia, tmp);
  return ht;
}
int treeDiameter(vvi &ed) {
  vvi tr(ed.size());
  unordered_map<int , Node2*> um(ed.size() + 1);
  for (int i = 0; i < ed.size()+1; ++i) {
    um[i] = new Node2(i);
  }
  for (auto &i: ed) {
    if (!um[i[0]]->left) um[i[0]]->left = um[i[1]];
    else um[i[0]]->right = um[i[1]];
  }
  int dis = 0;
  calc(um[0], dis);
  return dis-1;
}

int maisgn(){
  vvi v{{0,1},{1,2},{0,3},{3,4},{2,5},{3,6}};
  treeDiameter(v);
}