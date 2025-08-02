#include<bits/stdc++.h>
using namespace std;


void buildTree(int i,int l,int r){
    if(l<r)return;
    if(l == r)segmentTree[i] = nums[l];
    int mid = (l+r)/2;
    buildTree(2*i+1,l,mid);
    buildTree(2*i+2,mid+1,r);
    
}


int main(){
    cout<<"Hello world";
}