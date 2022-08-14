#include<bits/stdc++.h>
using namespace std;
//
// Created by sachet on 30/7/22.
//
vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
    unordered_map<char, int> w2;
    for(auto &w: words2){
        for(auto &i: w){
            if(!w2.count(i))w2[i] = 0;
            w2[i]++;
        }
    }
    vector<string>res;
    int cnt = w2.size();
    for(auto &w: words1){
        int charcnt = cnt;
        unordered_map<char, int>tmp(w2);
        for(auto &i: w){
            if(tmp.count(i)){
                if(tmp[i] > 0){
                    tmp[i] --;
                    if(tmp[i] == 0)charcnt --;
                }
            }
            if(charcnt == 0)break;
        }
        int flag = 1;
        for(auto &i: tmp){
            if(i.second != 0)flag = 0;
        }
        if(flag == 1)res.push_back(w);
    }
    return res;
}

int main2121(){
    vector<string> v{"amazon","apple","facebook","google","leetcode"};
    vector<string> w2{"e", "o"};
    wordSubsets(v, w2);
}