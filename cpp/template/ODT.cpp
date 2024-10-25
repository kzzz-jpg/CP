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
set<ODT> s;
IT split(int pos){
    IT it=s.lower_bound(ODT(pos));
    if(it!=s.end()&&it->l==pos) return it;  // 不用切的情況
    it--;  //不然一定在前一個
    int l=it->l,r=it->r;
    ll v=it->v;
    s.erase(it);
    s.insert(ODT(l,pos-1,v));
    return s.insert(ODT(pos,r,v)).first;
}
void update(int l,int r,ll v){
    IT R=split(r+1),L=split(l);
    s.erase(L,R);
    s.insert(ODT(l,r,v));
}
void inc(int l,int r,ll v){
    IT R=split(r+1),L=split(l);
    for(;L!=R;L++){
        L->v+=v;
    }
}
ll query(int l,int r,int k){
    IT R=split(r+1),L=split(l);
    vector<pair<ll,int>> v;
    for(;L!=R;L++){
        v.push_back(pair<ll,int>(L->v,L->r-L->l+1));
        //cerr<<v.back().first<<' '<<v.back().second<<'\n';
    }
    sort(v.begin(),v.end());
    for(auto at:v){
        k-=at.second;
        if(k<=0) return at.first;
    }
   // cerr<<"EEE\n";
}
ll n,q,a[200500],vmax,seed;
inline long long rg() 
{
    long long ret = seed;
    seed = (seed * 7LL + 13) % 1000000007LL;
    return ret;
}

int op,l,r,x,y;
ll fp(int res,int pw,int md){
    ll ret=1;
    while(pw){
        if(pw&1) ret=(ret*res)%md;
        res=(res*res)%md;
        pw>>=1;
    }
    return ret;
}
int query(int lL,int rr,int xx,int yy){
    ll ret=0;
    IT R=split(rr+1),L=split(lL);
    for(;L!=R;L++){
        ret=(ret+fp(L->v,xx,yy)*(L->l-L->r+1)%yy)%yy;
    }
    return ret;
}
signed main(){
    cin>>n>>q>>seed>>vmax;
    for(int i=1;i<=n;i++){
        a[i]=rg()%vmax+1;
        s.insert(ODT(i,i,a[i]));
    }
    s.insert(ODT(n+1,n+1,0));
    while(q--){
        op=rg()%4+1;
        l=rg()%n+1,r=rg()%n+1;
        if(l>r) swap(l,r);
        if(op==3) x=rg()%(r-l+1)+1;
        else x=rg()%vmax+1;
        if(op==4) y=rg()%vmax+1;
        if(op==1){
            inc(l,r,x);
        }else if(op==2){
            update(l,r,x);
        }else if(op==3){
           // cerr<<l<<' '<<r<<'\n';
            cout<<query(l,r,x)<<'\n';
        }else{
            cout<<query(l,r,x,y)<<'\n';
        }
    }
}