#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define IT set<ODT>::iterator
struct ODT{
    int l,r;
    mutable ll v;
    ODT(int L,int R=-1,ll V=0):l(L),r(R),v(V){}
    bool operator < (ODT A) const{
        return l<A.l;
    }
};
set<ODT> s[200500];
IT split(int pos,int x){
    IT it=s[x].lower_bound(ODT(pos));
    if(it!=s[x].end()&&it->l==pos) return it;  // 不用切的情況
    it--;  //不然一定在前一個
    int l=it->l,r=it->r;
    ll v=it->v;
    s[x].erase(it);
    s[x].insert(ODT(l,pos-1,v));
    return s[x].insert(ODT(pos,r,v)).first;
}
void update(int l,int r,ll v,int x){
    IT R=split(r+1),L=split(l);
    s[x].erase(L,R);
    s[x].insert(ODT(l,r,v));
}
void inc(int l,int r,ll v,int x){
    IT R=split(r+1,x),L=split(l,x);
    for(;L!=R;L++){
        L->v+=v;
    }
}
int tr[800500];
void modify(int l,int r,int L,int R,int v,int id){
    if(l>R||r<L) return;
    push(l,r,id);
    if(L<=l&&r<=R){
        tr[id]+=v;
        return;
    }
    int mid=l+r>>1;
    modify(l,mid,L,R,v,id<<1);
    modify(mid+1,r,L,R,v,id<<1|1);
}
int n,q,m;
signed main(){
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++) s[i].insert(ODT(1,m,0));
    int op,x,l,r;
    while(q--){
        cin>>op;
        if(op==1){
            cin>>l>>r>>x;
            inc(l,r,x)
        }
    }
}