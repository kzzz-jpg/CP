#include "bits/stdc++.h"
#include <ios>
using namespace std;
#define int long long
int pos[200500],mn[1010],sum[1010],lz[1010],sz,tot,a[200500];
int n,k,q;
#define IT set<ODT>::iterator
struct ODT{
    int l,r;
    mutable int v;
    ODT(int L,int R=-1,int V=0):l(L),r(R),v(V){}
    bool operator < (ODT A) const{
        return l<A.l;
    }
};
set<ODT> s;
IT split(int pos){
    IT it=s.lower_bound(ODT(pos));
    if(it!=s.end()&&it->l==pos) return it;
    it--;
    int l=it->l,r=it->r;
    int v=it->v;
    s.erase(it);
    s.insert(ODT(l,pos-1,v));
    return s.insert(ODT(pos,r,v)).first;
}
void update(int l,int r,int v){
    IT R=split(r+1),L=split(l);
    s.erase(L,R);
    s.insert(ODT(l,r,v));
}
int qry(int l,int r){
    int ret=0;
    IT R=split(r+1),L=split(l);
    for(;L!=R;L++){
        ret^=L->v;
    }
    return ret;
}
void upd(int l,int r,int v){
    if(pos[l]==pos[r]){
        for(int i=l;i<=r;i++) a[i]+=v;
        sum[pos[r]]=0;
        mn[pos[r]]=1e18;
        for(int i=(pos[l]-1)*sz+1;i<=pos[l]*sz;i++) sum[pos[i]]+=a[i]+lz[pos[i]],mn[pos[i]]=min(a[i]+lz[pos[i]],mn[pos[i]]);
        return;
    }
    for(int i=l;i<=pos[l]*sz;i++) a[i]+=v;
    for(int i=(pos[r]-1)*sz+1;i<=r;i++) a[i]+=v;
    for(int i=pos[l]+1;i<=pos[r]-1;i++) lz[i]+=v,mn[i]+=v,sum[i]+=v*sz;
    sum[pos[l]]=sum[pos[r]]=0;
    mn[pos[l]]=mn[pos[r]]=1e18;
    for(int i=(pos[l]-1)*sz+1;i<=pos[l]*sz;i++) sum[pos[i]]+=a[i]+lz[pos[i]],mn[pos[i]]=min(a[i]+lz[pos[i]],mn[pos[i]]);
    for(int i=(pos[r]-1)*sz+1;i<=pos[r]*sz;i++) sum[pos[i]]+=a[i]+lz[pos[i]],mn[pos[i]]=min(a[i]+lz[pos[i]],mn[pos[i]]);
}
int qrySum(int l,int r){
    int ret=0;
    if(pos[l]==pos[r]){
        for(int i=l;i<=r;i++) ret+=a[i]+lz[pos[i]];
        return ret;
    }
    for(int i=l;i<=pos[l]*sz;i++) ret+=a[i]+lz[pos[i]];
    for(int i=(pos[r]-1)*sz+1;i<=r;i++) ret+=a[i]+lz[pos[i]];
    for(int i=pos[l]+1;i<=pos[r]-1;i++) ret+=sum[i];
    return ret;
}
int qryMin(int l,int r){
    int ret=1e18;
    if(pos[l]==pos[r]){
        for(int i=l;i<=r;i++) ret=min(a[i]+lz[pos[i]],ret);
        return ret;
    }
    for(int i=l;i<=pos[l]*sz;i++) ret=min(a[i]+lz[pos[i]],ret);
    for(int i=(pos[r]-1)*sz+1;i<=r;i++) ret=min(a[i]+lz[pos[i]],ret);
    for(int i=pos[l]+1;i<=pos[r]-1;i++) ret=min(ret,mn[i]);
    return ret;
}
signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin>>n>>k>>q;
    sz=sqrt(n);
    tot=n/sz;
    if(n%sz) tot++;
    for(int i=1;i<=n;i++){
        pos[i]=(i-1)/sz+1;
    }
    int tmp;
    for(int i=1;i<=k;i++) {
        cin>>tmp;
        s.insert(ODT(i,i,tmp));
    }
    int op,l,r,L,R;
    while(q--){
        cin>>op;
        if(op==1){
            cin>>l>>r>>L>>R;
            upd(l,r,qry(L,R));
            update(L, R, 0);
        }else{
            cin>>l>>r;
            cout<<qrySum(l,r)<<'\n';
            upd(l,r,-qryMin(l,r));
        }
        upd(1,n,1);
    }
}