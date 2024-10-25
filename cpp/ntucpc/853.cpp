#include<bits/stdc++.h>
using namespace std;
#define int long long
#define IT set<ODT>::iterator
struct ODT{
    int l,r;
    mutable int v;
    ODT(int L,int R=-1,int V=0):l(L),r(R),v(V){}
    bool operator < (ODT a) const{
        return l<a.l;
    }
};
set<ODT> s;
IT split(int pos){
    IT it=s.lower_bound(ODT(pos));
    if(it!=s.end()&&it->l==pos) return it;
    it--;
    int l=it->l,r=it->r,v=it->v;
    s.erase(it);
    s.insert(ODT(l,pos-1,v));
    return s.insert(ODT(pos,r,v)).first;
}
void tp(int l,int r,int v){
    IT R=split(r+1),L=split(l);
    s.erase(L,R);
    s.insert(ODT(l,r,v));
}
int query(int l,int r){
    map<int,int> mp;
    IT R=split(r+1),L=split(l);
    for(;L!=R;L++){
        if(L->v) mp[L->v]+=(L->r-L->l+1);
    }
    int ret=0;
    for(auto at:mp){
        ret+=at.second*at.second;
    }
    return ret;
}
int n,q,x,y,z,op;
int a[500050];
signed main(){
    cin>>n>>q;
    s.insert(ODT(1,n+1,0));
    while(q--){
        cin>>op>>x>>y;
        if(op==1){
            cin>>z;
            tp(x,y,z);
        }else{
            cout<<query(x,y)<<'\n';
            tp(x,y,0);
        }
    }
}