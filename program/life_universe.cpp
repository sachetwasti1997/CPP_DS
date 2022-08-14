#include<bits/stdc++.h>
using namespace std;
//
// Created by sachet on 29/7/22.
//

int todo(){
//    while(true){
//        int x;
//        cin>>x;
//        if (x == 42){
//            break;
//        }
//        cout<<x<<endl;
//    }
    string str;
//    cin>>str;
    int i = 0, j = str.length() - 1, flag = 0;
    while(i < j){
        if(str[i] != str[j]){
            flag = 1;
            break;
        }
        i++;
        j--;
    }
    if (flag == 1)cout<<"Not Palindrome";
    else cout<<"Palindrome";
    unordered_map<int, int> mp(1000000);
    cout<<mp.bucket_count();
    return 0;
}
