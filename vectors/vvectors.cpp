#include<bits/stdc++.h>
using namespace std;
//
// Created by sachet on 28/7/22.
//
void vvectors(){
    vector<int> v;

//    v.push_back(1);
    v.emplace_back(2);

    vector<int> v2(5, 20);
//    vector<int>::iterator it = v.begin()
    auto itt = v2.begin();
    cout<<*itt<<"\n ";
    auto it1 = v2.begin();
    auto it2 = v2.end();
    auto it3 = v2.rbegin();
    auto it4 = v2.rend();
    for (auto it = v2.begin();  it!=v2.end() ; it++) {
        cout<<*(it)<<" ";
    }
    for (auto i: v2) {
        cout<<i<<" ";
    }
}

//int main(){
//    vvectors();
//}