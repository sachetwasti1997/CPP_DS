//
// Created by sachet on 9/8/22.
//
/**
*
void sum(NestedInteger nL, int dpth, int &sm){
    if (nL.isInteger()) sm += dpth * nL.getInteger();
    else{
        for (auto &i: nL.getList()){
            sum (i, dpth+1, sm);
        }
    }
}

int depthSum(vN& nL) {
    int dpth = 1, sm = 0;
    for (auto &i: nL) sum(i, 1, sm);
    return sm;
}
*/