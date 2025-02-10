#include "bits/stdc++.h"
using namespace std;
#define int long long
int a[1000500];
int n,k,q;
int tr[800500],mn[800500];
int lz[800500],xlz[4000500],x[4000500];
void push(int l,int r,int id){
    if(l==r) return;
    int mid=l+r>>1;
    tr[id<<1]+=(mid-l+1)*lz[id];
    mn[id<<1]+=lz[id];
    lz[id<<1]+=lz[id];
    tr[id<<1|1]+=(r-(mid+1)+1)*lz[id];
    mn[id<<1|1]+=lz[id];
    lz[id<<1|1]+=lz[id];
    lz[id]=0;
}
void pushXor(int l,int r,int id){
    if(l>=r) return;
    int mid=l+r>>1;
    if(xlz[id]==-1){
        xlz[id<<1|1]=xlz[id<<1]=-1;
        x[id<<1|1]=x[id<<1]=0;
    }
}
int querySum(int l,int r,int L,int R,int id){
    if(L>r||R<l) return 0;
    push(l,r,id);
    if(L<=l&&r<=R) return tr[id];
    int mid=l+r>>1;
    return querySum(l,mid,L,R,id<<1)+querySum(mid+1,r,L,R,id<<1|1);
}
int queryMin(int l,int r,int L,int R,int id){
    if(L>r||R<l) return 1e18;
    push(l,r,id);
    if(L<=l&&r<=R) return mn[id];
    int mid=l+r>>1;
    return min(queryMin(l,mid,L,R,id<<1),queryMin(mid+1,r,L,R,id<<1|1));
}
void modify(int l,int r,int L,int R,int v,int id){
    if(L>r||R<l) return;
    push(l,r,id);
    if(L<=l&&r<=R){
        lz[id]+=v;
        tr[id]+=(r-l+1)*v;
        mn[id]+=v;
        return;
    }
    int mid=l+r>>1;
    modify(l,mid,L,R,v,id<<1);
    modify(mid+1,r,L,R,v,id<<1|1);
    tr[id]=tr[id<<1]+tr[id<<1|1];
    mn[id]=min(mn[id<<1],mn[id<<1|1]);
}
void build(int l,int r,int id){
    if(l==r){
        x[id]=a[l];
        //cerr<<l<<' '<<x[id]<<'\n';
        return;
    }
    int mid=l+r>>1;
    build(l,mid,id<<1);
    build(mid+1,r,id<<1|1);
    x[id]=x[id<<1]^x[id<<1|1];
}
int queryXor(int l,int r,int L,int R,int id){
    //cerr<<l<<' '<<r<<'\n';
    if(L>r||R<l) return 0;

    pushXor(l,r,id);
    if(L<=l&&r<=R) return x[id];
    int mid=l+r>>1;
    return queryXor(l,mid,L,R,id<<1)^queryXor(mid+1,r,L,R,id<<1|1);
}
void modifyXor(int l,int r,int L,int R,int id){
    if(L>r||R<l) return;
    pushXor(l,r,id);
    if(L<=l&&r<=R){
        x[id]=0;
        xlz[id]=-1;
        return;
    }
    int mid=l+r>>1;
    modifyXor(l,mid,L,R,id<<1);
    modifyXor(mid+1,r,L,R,id<<1|1);
    x[id]=x[id<<1]^x[id<<1|1];
}
signed main(){
    cin>>n>>k>>q;
    for(int i=1;i<=k;i++){
        cin>>a[i];
    }
    build(1,k,1);
    //cerr<<'\n';
    int l,r,L,R,op;
    while(q--){
        cin>>op;
        if(op==1){
            cin>>L>>R>>l>>r;
            //cerr<<l<<' '<<r<<'\n';
            //cerr<<queryXor(1,n,l,l,1)<<' '<<queryXor(1,n,r,r,1)<<'\n';
            //cerr<<queryXor(1,n,l,r,1)<<'\n';
            modify(1,n,L,R,queryXor(1,k,l,r,1),1);
            modifyXor(1,k,l,r,1);
        }else{
            cin>>l>>r;
            cout<<querySum(1,n,l,r,1)<<'\n';
            modify(1,n,l,r,-queryMin(1,n,l,r,1),1);
        }
        modify(1,n,1,n,1,1);
    }
}