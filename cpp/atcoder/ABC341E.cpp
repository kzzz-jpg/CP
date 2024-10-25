#include<bits/stdc++.h>
using namespace std;
struct node{
    int l,r;
    bool is,lz;
}tr[2000500];
int a[1000500];
void build(int l,int r,int id){
    if(l==r){
        tr[id].l=tr[id].r=a[l];
        tr[id].is=1;
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,id<<1);
    build(mid+1,r,id<<1|1);
    tr[id].l=tr[id<<1].l;
    tr[id].r=tr[id<<1|1].r;
    tr[id].is=tr[id<<1].is&&tr[id<<1|1].is&&tr[id<<1].r!=tr[id<<1|1].l;
}
void push(int id){
    if(tr[id].lz){
        tr[id<<1].l^=1;
        tr[id<<1].r^=1;
        tr[id<<1|1].l^=1;
        tr[id<<1|1].r^=1;
        tr[id<<1].lz^=1;
        tr[id<<1|1].lz^=1;
    }
    tr[id].lz=0;
};
void modify(int l,int r,int L,int R,int id){
    if(l>R||r<L) return;
    if(L<=l&&r<=R){
        tr[id].l^=1;
        tr[id].r^=1;
        tr[id].lz^=1;
        return;
    }
    push(id);
    int mid=(l+r)>>1;
    modify(l,mid,L,R,id<<1);
    modify(mid+1,r,L,R,id<<1|1);
    tr[id].l=tr[id<<1].l;
    tr[id].r=tr[id<<1|1].r;
    tr[id].is=tr[id<<1].is&&tr[id<<1|1].is&&tr[id<<1].r!=tr[id<<1|1].l;
}
node query(int l,int r,int L,int R,int id){
    if(L<=l&&r<=R){
        return tr[id];
    }
    push(id);
    int mid=(l+r)>>1;
    if(R<=mid) return query(l,mid,L,R,id<<1);
    else if(L>mid) return query(mid+1,r,L,R,id<<1|1);
    node lnd=query(l,mid,L,R,id<<1);
    node rnd=query(mid+1,r,L,R,id<<1|1);
    node ret;
    ret.l=lnd.l;
    ret.r=rnd.r;
    ret.is=lnd.is&&rnd.is&&lnd.r!=rnd.l;
    return ret;
}
int n,m,op,l,r;
char c;
signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>c;
        a[i]=c-'0';
    }
    build(1,n,1);
    while(m--){
        cin>>op>>l>>r;
        if(op==1){
            modify(1,n,l,r,1);
        }else{
            if(query(1,n,l,r,1).is){
                cout<<"Yes\n";
            }else{
                cout<<"No\n";
            }
        }
    }
}