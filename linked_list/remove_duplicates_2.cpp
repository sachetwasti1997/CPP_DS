//
// Created by sachet on 14/8/22.
//
#include "ListNode.h"
#include <bits/stdc++.h>
using namespace std;

ListNode* deleteDuplicates(ListNode* hd) {
  if (!hd || !hd->next) return hd;
  unordered_map<int, int> um;
  auto head = hd;
  while (hd) {
    um[hd->val]++;
    hd = hd->next;
  }
  while (head && um[head->val] > 1) head = head->next;
  if (!head) return nullptr;
  auto newhd = head;
  while (head) {
    auto ptr = head->next;
    while (ptr and um[ptr->val] > 1) {
      ptr = ptr->next;
    }
    head->next = ptr;
    head = head->next;
  }
  return newhd;
}