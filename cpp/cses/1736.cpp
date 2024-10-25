#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200050],tr[1000050],lz[1000050];
int n,q;
void build(int l,int r,int id){
    if(l==r){
        tr[id]=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(1,mid,id<<1);
    build(mid+1,r,id<<1|1);
}
void modify(int l,int r,int L,int R,int st,int id){
    if(L>r||R<l) return;
    if(L<=l&&r<=R){
        lz[id]=st;
        tr[id]+=(st*2+r-l)*(r-l+1)/2;
        return;
    }
    int mid=(l+r)>>1;
    modify(l,mid,L,R,st,id<<1);
    modify(mid+1,r,L,R,st+(mid-st),id<<1|1);
    tr[id]=tr[id<<1]+tr[id<<1|1];
}
int query(int l,int r,int L,int R,int id){
    if(l>R||r<l) return 0;
    if(L<=l&&r<=R) return tr[id];
    int mid=(l+r)>>1;
    return query(l,mid,L,R,id<<1)+query(mid+1,r,L,R,id<<1|1);
}