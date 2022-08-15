//
// Created by sachet on 14/8/22.
//
#include "ListNode.h"
#include <bits/stdc++.h>
using namespace std;

/**
 * O(n^2) Algorithm
 * @param hd
 * @return
 */
ListNode* removeZeroSumSublists(ListNode* hd) {
  vector<int> v;
  int s = -1, e = -1;
  for (auto h = hd; h != nullptr; h = h->next) v.emplace_back(h->val);
  for (int i=0; i<v.size()-1; i++) {
    int sm = v[i];
    for (int j=i+1; j<v.size(); j++) {
      sm += v[j];
      if (sm == 0){
        s = i;
        e = j;
        break;
      }
    }
    if (s != -1) for (int k=s; k<=e; k++) v[k] = 0;
  }
  hd = nullptr;
  ListNode *tl{nullptr};
  for (int i : v) {
    if (i != 0) {
      if (!hd) {
        hd = new ListNode(i);
        tl = hd;
      }else {
        tl->next = new ListNode(i);
        tl = tl->next;
      }
    }
  }
  return hd;
}