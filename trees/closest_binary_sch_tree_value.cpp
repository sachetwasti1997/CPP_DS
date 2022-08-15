//
// Created by sachet on 14/8/22.
//
#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
typedef vector<int> vi;

struct Node{
  int val;
  double diff;
  Node(int x, double y): val(x), diff(y){}
};

struct comp{
  bool operator()(Node const &n1, Node const &n2) {
    return n1.diff < n2.diff;
  }
};

void find(TreeNode *r, double t, int k,
          priority_queue<Node, vector<Node>, comp> &pq) {
  if (!r) return;
  if (pq.empty()) pq.push(Node(r->val, abs(t-r->val)));
  else{
    pq.push(Node(r->val, abs(t-r->val)));
    if (pq.size() > k) pq.pop();
  }
  find(r->left, t, k, pq);
  find(r->right, t, k, pq);
}

vi closestKValues(TreeNode* root, double t, int k) {
  priority_queue<Node, vector<Node>, comp>pq;
  find(root, t, k, pq);
  vi res;
  while (!pq.empty()) {
    res.emplace_back(pq.top().val);
    pq.pop();
  }
  return res;
}