//
// Created by sachet on 12/8/22.
//

/**
* void max_depth (NI &n, int depth, int &d) {
d = max(d, depth);
if (!n.isInteger()){
  for (auto &i: n.getList()) max_depth (i, depth+1, d);
}
}

void depth(NI &n, int dpth, int &res, int d) {
if (n.isInteger()) res += (d - dpth + 1)*n.getInteger();
else {
  for (auto &i: n.getList()) {
    depth(i, dpth+1, res, d);
  }
}
}

int depthSumInverse(vector<NestedInteger>& nL) {
int d = 1, res = 0;
for (auto &i: nL) max_depth(i, 1, d);
for (auto &i: nL) {
  depth(i, 1, res, d);
}
return res;
}
*/