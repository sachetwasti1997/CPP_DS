#include<bits/stdc++.h>
using namespace std;
//
// Created by sachet on 1/8/22.
//
typedef vector<int> vec_int;

class Solution {
private:
    vector<vec_int> v;
public:
    int dfs(int i, int j, int m, int n){
        if(i < 0 || j < 0 || i >= m || j >= n)return 0;
        if(i == m - 1 && j == n - 1)return 1;
        if(v[i][j] != -1)return v[i][j];
        return v[i][j] = dfs(i + 1, j, m, n) + dfs(i, j + 1, m, n);
    }
    int uniquePaths(int m, int n) {
        v = vector<vec_int>(m, vec_int(n, -1));
        return dfs(0, 0, m, n);
    }
};

int mainhjgh(){
    auto *s = new Solution();
    int v = s->uniquePaths(3,2);
    stack<int> st;

    cout<<v;
}