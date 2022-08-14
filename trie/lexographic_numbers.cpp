//
// Created by sachet on 12/8/22.
//
/**
 * Here idea is pretty simple,
 * call through the dfs of each number less than or equal to range and
 * in second iteration just multiply 10 to current number and pass through same dfs
 */
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

void dfs (int start, int end, int n, vi &res) {
  for (int i=start; i<=end && i <=n; i++) {
    res.emplace_back(i);
    dfs(i*10, i*10+9, n, res);
  }
}

vi lexicalOrder(int n) {
  if (n == 1) return vi{1};
  vi res;
  dfs(1, 9, n, res);
  return res;
}