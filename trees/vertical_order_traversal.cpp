//
// Created by sachet on 10/8/22.
//

#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vvi;

struct TreeNode{
  int val;
  TreeNode *left, *right;
};

class Solution {
  public:

  struct Node{
    TreeNode *val;
    int pos;
  };

  vvi verticalOrder(TreeNode* root) {
    if (!root) return vvi{};

    map<int, vector<int>> mp;
    queue<Node> q;
    int sz = 1;
    q.push({root, 0});
    while (!q.empty()){
      for (int i=0; i<sz; i++) {
        Node tmp = q.front();
        q.pop();
        mp[tmp.pos].emplace_back(tmp.val->val);
        if (tmp.val->left)
          q.push({tmp.val->left, tmp.pos-1});
        if (tmp.val->right)
          q.push({tmp.val->right, tmp.pos+1});
      }
      sz = q.size();
    }
    vvi res;
    for (auto &i: mp) {
      res.emplace_back(i.second);
    }
    return res;
  }
};

typedef vector<int> vi;
typedef pair<int, int> pi;

int maingh(){
  auto hsh = [](const vi &v){
    hash<int> hasher;
    size_t seed = 0;
    for (int i: v) seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
    return seed;
  };
  auto prhsh = [](const pi &p1){
    hash<int> h;
    size_t seed = 0;
    seed ^= (h(p1.first)+0x93779b9+(seed<<6)+(seed>>2));
    seed ^= (h(p1.second)+0x93779b9+(seed<<6)+(seed>>2));
    return seed;
  };

  vi v1{1, 2, 3, 4, 5};
  vi v2{1, 2, 3, 4, 5};
  unordered_set<vector<int>, decltype(hsh)> st(10, hsh);
  unordered_set<pi, decltype(prhsh)> pst(1000, prhsh);

  for (int i=0; i<15; i++){
    vi v{i};
    st.insert(v);
  }
  st.insert({14});
  for (auto &i: st) {
    cout<<"Vector: ";
    for (auto &el: i)
      cout << el <<" ";
    cout<<endl;
  }

  for (int i=0; i<1000; i++) pst.insert({i, i+1});
  pst.insert({9,10});
  for (auto &i: pst){
    cout<<"Pair: "<<i.first<<", "<<i.second;
    cout<<endl;
  }
}













