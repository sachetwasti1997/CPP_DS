#include<bits/stdc++.h>
using namespace std;
//
// Created by sachet on 29/7/22.
//
struct ListNode{
    int val;
    ListNode *next;
    explicit ListNode(int x): val(x), next(nullptr){}
};
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    auto *res = new ListNode(-1);
    auto *tail = res;
    int carry = 0;
    while(l1 || l2){
        int x = l1 ? l1 -> val : 0;
        int y = l2 ? l2 -> val : 0;
        int total = carry + x + y;
        carry = carry / 10;
        tail -> next = new ListNode(total % 10);
        l1 = l1 ? l1 -> next: nullptr;
        l2 = l2 ? l2 -> next: nullptr;
        tail = tail->next;
    }
    return res -> next;
}