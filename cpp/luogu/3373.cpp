#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q,P,a[200500];
int tr[800500],lz[800500],mul[800500];
void push(int l,int r,int id){
    if(l==r) return;
    int mid=l+r>>1;
    tr[id<<1]=(tr[id<<1]%P*mul[id]%P)%P;
    tr[id<<1|1]=(tr[id<<1|1]%P*mul[id]%P)%P;
    mul[id<<1]=(mul[id<<1]%P*mul[id]%P)%P;
    mul[id<<1|1]=(mul[id<<1|1]%P*mul[id]%P)%P;
    tr[id<<1]=(tr[id<<1]+lz[id]*(mid-l+1))%P;
    tr[id<<1|1]=(tr[id<<1|1]+lz[id]*(r-mid))%P;
    lz[id<<1]=(lz[id<<1]*mul[id]%P+lz[id])%P;
    lz[id<<1|1]=(lz[id<<1|1]*mul[id]%P+lz[id])%P;
    lz[id]=0;
    mul[id]=1;
}
void build(int l,int r,int id){
    mul[id]=1;
    if(l==r) {
        tr[id]=a[l];
        mul[id]=1;
        return;
    }
    int mid=l+r>>1;
    build(l,mid,id<<1);
    build(mid+1,r,id<<1|1);
    tr[id]=(tr[id<<1]+tr[id<<1|1])%P;
}
void add(int l,int r,int L,int R,int v,int id){
    if(l>R||r<L) return;
    push(l,r,id);
    if(L<=l&&r<=R){
        tr[id]+=(r-l+1)*v;
        tr[id]%=P;
        lz[id]+=v;
        lz[id]%=P;
        return;
    }
    int mid=l+r>>1;
    add(l,mid,L,R,v,id<<1);
    add(mid+1,r,L,R,v,id<<1|1);
    tr[id]=tr[id<<1]+tr[id<<1|1];
    tr[id]%=P;
}
void multi(int l,int r,int L,int R,int v,int id){
    if(l>R||r<L)return ;
    push(l,r,id);
    if(L<=l&&r<=R) {
        tr[id]=(tr[id]%P*v%P)%P;
        mul[id]=(mul[id]%P*v%P)%P;
        return;
    }
    int mid=l+r>>1;
    multi(l,mid,L,R,v,id<<1);
    multi(mid+1,r,L,R,v,id<<1|1);
    tr[id]=(tr[id<<1]+tr[id<<1|1])%P;
}
int query(int l,int r,int L,int R,int id){
    if(l>R||r<L) return 0;
    push(l,r,id);
    if(L<=l&&r<=R) return tr[id];
    int mid=l+r>>1;
    return (query(l,mid,L,R,id<<1)+query(mid+1,r,L,R,id<<1|1))%P;
}
signed main(){
    scanf("%lld%lld%lld",&n,&q,&P);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    int op,l,r,k;
    build(1,n,1);
    while(q--){
        scanf("%lld",&op);
        if(op==1){
            scanf("%lld%lld%lld",&l,&r,&k);
            multi(1,n,l,r,k,1);
        }else if(op==2){
            scanf("%lld%lld%lld",&l,&r,&k);
            add(1,n,l,r,k,1);
        }else{
            scanf("%lld%lld",&l,&r);
            printf("%lld\n",query(1,n,l,r,1)%P);
        }
    }
}