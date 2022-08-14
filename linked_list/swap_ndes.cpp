#include <bits/stdc++.h>
using namespace std;
//
// Created by sachet on 7/8/22.
//

class Solution {
public:

  struct ListNode{
    int val;
    ListNode *next;
  };

  ListNode* swapNodes(ListNode* head, int k) {
    ListNode *h{nullptr}, *t{nullptr};
    for(auto i = head; i != nullptr; i = i -> next){
      t = t ? t->next: nullptr;
      if(--k == 0){
        t = head;
        h = i;
      }
    }
    if(h && t){
      int temp = h->val;
      h->val = t->val;
      t->val = temp;
    }
    return head;
  }

};

int mainfghg(){
  vector<vector<int>> v{{1},{1,1}};
  v.push_back({1,1,1});
  for (auto &i: v) {
    for(auto &j: i){
      cout<<j<<" ";
    }
    cout<<endl;
  }
}