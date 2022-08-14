#include<bits/stdc++.h>
using namespace std;
//
// Created by sachet on 29/7/22.
//

bool findcycle(unordered_map<int, vector<int>> &mp, unordered_set<int> &v, unordered_set<int> &bv, int n){
    v.insert(n);
    bv.insert(n);
    for(auto i: mp[n]){
        if(!v.count(i) && findcycle(mp, v, bv, i))return true;
        else if(bv.count(i))return true;
    }
    bv.erase(n);
    return false;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    if(prerequisites.empty())return true;
    unordered_map<int, vector<int>> g(numCourses);
    unordered_set<int> visit(numCourses), bvisit(numCourses);
    for (auto i: prerequisites) g[i[0]].push_back(i[1]);
    for( auto i: g){
        if(!visit.count(i.first) && findcycle(g, visit, bvisit, i.first))return false;
    }
    return true;
}

bool canFinish2(int n, vector<vector<int>>& p) {
    unordered_map<int, vector<int>> g(n);
    vector<int> deg(n, 0);
    for(int i=0; i<n; i++)g[i] = vector<int>();
    for(auto &e: p)
        g[e[0]].push_back(e[1]), deg[e[1]]++;
    queue<int> q;
    int cnt = 0;
    for(int i=0; i<n; i++)
        if(!deg[i])q.push(i);
    while (!q.empty()){
        int s = q.size();
        for(int j = 0; j < s; j++){
            int t = q.front();
            q.pop();
            for(auto &i: g[t]){
                deg[i]--;
                if(deg[i] == 0)
                    q.push(i); cnt++;
            }
        }
    }
    return cnt == n;
}