#include<bits/stdc++.h>
using namespace std;
#define int long long
#define IT set<ODT>::iterator
struct ODT{
    int l,r;
    mutable int v;
    bool operator < (ODT o) const{
        return l<o.l;
    }
    ODT(int L,int R=-1,int V=0):l(L),r(R),v(V){}
};
set<ODT> odt;
IT split(int pos){
    IT it=odt.lower_bound(ODT(pos));
    if(it!=odt.end()&&it->l==pos) return it;
    it--;
    int l=it->l,r=it->r,v=it->v;
    odt.erase(it);
    odt.insert(ODT(l,pos-1,v));
    return odt.insert(ODT(pos,r,v)).first;
}
void tp(int l,int r,int v){
    IT itr=split(r+1),itl=split(l);
    odt.erase(itl,itr);
    odt.insert(ODT(l,r,v));
}
int query(int l,int r){
    auto itl=odt.lower_bound(ODT(l)),itr=odt.lower_bound(ODT(r));
    if(itl==odt.end()||itl->l!=l) itl--;
    if(itr!=odt.end()&&itr->l==r) itr++;
    int ret=0;
    map<int,int> mp;
    for(;itl!=itr;itl++){
        if(itl->v!=0&&mp[itl->v]++==0) ret++;
    }
    return ret;
}
int n,m,q,ql,qr,qc;
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m>>q;
    odt.insert(ODT(0,n+1,0));
    while(m--){
        cin>>ql>>qr>>qc;
        tp(ql,qr,qc);
    }
    while(q--){
        cin>>ql>>qr;
        cout<<query(ql,qr)<<'\n';
    }
}