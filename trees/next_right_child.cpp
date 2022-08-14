//
// Created by sachet on 8/8/22.
//
#include <bits/stdc++.h>
using namespace std;

class Node{
public:
  int val;
  Node *left, *right, *next;
  Node(int x): val(x), left(nullptr), right(nullptr), next(nullptr){}
};

Node* connect(Node* root) {
  if (!root) return root;
  queue<Node*> q;
  if (root->left) q.push(root -> left);
  if (root -> right) q.push(root -> right);
  int sz = 2;
  while(!q.empty()){
    for (int i = 0; i < sz; i++){
      Node* tmp{nullptr};
      tmp = q.front();
      q.pop();
      if (i < sz - 1)tmp -> next = q.front();
      if (tmp->left) q.push(tmp -> left);
      if (tmp->right) q.push(tmp -> right);
    }
    sz = q.size();
  }
  return root;
}

auto connect2(Node* root) {
  if (!root) return root;
  Node *lft = root;
  while (lft->left){
    Node *tmp{nullptr}, *tmp2 = lft;
    while (tmp2){
      if(tmp) tmp->next = tmp2->left;
      tmp = tmp2 -> left;
      tmp->next = tmp2->right;
      tmp = tmp -> next;
      tmp2 = tmp2 -> next;
    }
    lft = lft -> left;
  }
  return root;
}

int mainsdfg(){
  Node * f1 = new Node(1);
  Node * f2 = new Node(2);
  Node * f3 = new Node(3);
  Node * f4 = new Node(4);
  Node * f5 = new Node(5);
  Node * f6 = new Node(6);
  Node * f7 = new Node(7);

  f1 -> left = f2;
  f1 -> right = f3;
  f2 -> left = f4;
  f2 -> right = f5;
  f3 -> left = f6;
  f3 -> right = f7;

  connect2(f1);
}


















