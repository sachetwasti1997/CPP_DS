//
// Created by sachet on 14/8/22.
//

#ifndef DATA_STRUCTURES_LISTNODE_H
#define DATA_STRUCTURES_LISTNODE_H

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#endif//DATA_STRUCTURES_LISTNODE_H
