#include<bits/stdc++.h>
using namespace std;

vector<string> findAndReplacePattern(vector<string>& words, string& pattern) {
    vector<string> res{};
    for(const string&  i: words){
        unordered_map<char, char> mp;
        unordered_map<char, char>mp2;
        int k = 0, flag = -1;
        for(auto it: pattern){
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
    return res;
}

string construct(string &s){
    unordered_map<char, int>mp;
    for(char a: s)if(!mp.count(a))mp[a] = mp.size();
    for(int i = 0; i < s.length(); i++)s[i] = 'a'+s[mp[s[i]]];
    return s;
}

vector<string> findAndReplacePattern2(vector<string>& words, string& pattern) {
    pattern = construct(pattern);
    vector<string> res{};
    for (auto s: words)if (construct(s) == pattern)res.push_back(s);
    return res;
}
