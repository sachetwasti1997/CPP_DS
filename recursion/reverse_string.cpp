//
// Created by sachet on 14/8/22.
//
#include <bits/stdc++.h>
using namespace std;

void reverseString(vector<char>& s) {
  unsigned int i = 0, j = s.size()-1;
  while (i < j) {
    char tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
    i++;
    j--;
  }
}