#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,q,a[200500];
int tr[800500],lz[800500];
void push(int l,int r,int id){
    if(l==r) return;
    int mid=l+r>>1;
    tr[id<<1]+=lz[id]*(mid-l+1);
    lz[id<<1]+=lz[id];
    tr[id<<1|1]+=lz[id]*(r-mid);
    lz[id<<1|1]+=lz[id];
    lz[id]=0;
}
void build(int l,int r,int id){
    if(l==r){
        tr[id]=a[l];
        return;
    }
    int mid=l+r>>1;
    build(l,mid,id<<1);
    build(mid+1,r,id<<1|1);
    tr[id]=tr[id<<1]+tr[id<<1|1];
}
void modify(int l,int r,int L,int R,int v,int id){
    if(l>R||r<L) return;
    push(l,r,id);
    if(L<=l&&r<=R){
        tr[id]+=(r-l+1)*v;
        lz[id]+=v;
        return;
    }
    int mid=l+r>>1;
    modify(l,mid,L,R,v,id<<1);
    modify(mid+1,r,L,R,v,id<<1|1);
    tr[id]=tr[id<<1]+tr[id<<1|1];
}
int query(int l,int r,int L,int R,int id){
    if(l>R||r<L) return 0;
    push(l,r,id);
    if(L<=l&&r<=R) return tr[id];
    int mid=l+r>>1;
    return query(l,mid,L,R,id<<1)+query(mid+1,r,L,R,id<<1|1);
}
signed main(){
    scanf("%lld%lld",&n,&q);
    for(int i=1;i<=n;i++) scanf("%lld",a+i);
    int l,r,k,op;
    build(1,n,1);
    while(q--){
        scanf("%lld",&op);
        if(op==1){
            scanf("%lld%lld%lld",&l,&r,&k);
            modify(1,n,l,r,k,1);
        }else{
            scanf("%lld%lld",&l,&r);
            printf("%lld\n",query(1,n,l,r,1));
        }
    }
}