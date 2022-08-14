#include <bits/stdc++.h>
using namespace std;
//
// Created by sachet on 29/7/22.
//
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(nullptr){}
};

ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    ListNode *l = nullptr, *r = nullptr;
    ListNode * h = list1;
    int l1 = 0, r1 = 0;
    while(h){
        if(l1 == a-1) l = h;
        if (r1 == b)r = h;
        h = h -> next;
        l1++;
        r1++;
    }
    l->next = list2;
    while (list2 -> next != nullptr)list2 = list2->next;
    list2->next = r;
    return list1;
}

ListNode* mergeInBetween2(ListNode* list1, int a, int b, ListNode* list2) {
    ListNode *l1 = list1, *l2 = list1;
    for(int i = 0; i < a - 1; i++) l1 = l1 -> next;
    for(int i = 0; i < b; i++) l2 = l2 -> next;
    l1 -> next = list2;
    while(list2 -> next)list2 = list2 -> next;
    list2 -> next = l2;
    return list1;
}



int main111(){
    string s1{"Sachet"};
    vector<string> words = {"abc","deq","mee","aqq","dkd","ccc"};
    string pattern = "abb";
    vector<string> res{};
    for(const string&  i: words){
        unordered_map<char, char> mp;
        unordered_map<char, char>mp2;
        int k = 0, flag = -1;
        for(auto it: pattern){
            if(k > i.length()){
                flag = 0;
                break;
            }
            if (mp.find(it) == mp.end()){
                mp[it] = i[k];
            }else if(mp[it] != i[k]){
                flag = 0;
                break;
            }
            if (mp2.find(i[k]) == mp2.end()){
                mp2[i[k]] = it;
            }else if (mp2[i[k]] != it){
                flag = 0;
                break;
            }
            k++;
        }
        if (flag != 0)res.push_back(i);
    }
    for (auto & re : res) {
        cout<<re<<" ";
    }
}






