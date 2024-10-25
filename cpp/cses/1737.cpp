#include<bits/stdc++.h>
using namespace std;
#define int long long
struct nd{
    int l,r,val;
} tr[4600005];
int a[200005],tim[200005];
int n,q;
int cnt,tmcnt;
int build(int l,int r){
    int nw=cnt++;
    if(l==r){
        tr[nw].val=a[l];
        return nw;
    }
    int mid=(l+r)>>1;
    tr[nw].l=build(l,mid);
    tr[nw].r=build(mid+1,r);
    tr[nw].val=tr[tr[nw].l].val+tr[tr[nw].r].val;
    return nw;
}
nd cop(int id){
    nd ret=tr[id];
    return ret;
}
int modify(int l,int r,int x,int v,int id){
    int nw=cnt++;
    tr[nw]=cop(id);
    if(l==r){
        tr[nw].val=v;
        return nw;
    }
    int mid=(l+r)>>1;
    if(x<=mid){
        tr[nw].l=modify(l,mid,x,v,tr[id].l);
    }else{
        tr[nw].r=modify(mid+1,r,x,v,tr[id].r);
    }
    tr[nw].val=tr[tr[nw].l].val+tr[tr[nw].r].val;
    return nw;
}
int query(int l,int r,int L,int R,int id){
    if(L>r||R<l) return 0;
    if(L<=l&&r<=R){
        return tr[id].val;
    }
    int mid=(l+r)>>1;
    return query(l,mid,L,R,tr[id].l)+query(mid+1,r,L,R,tr[id].r);
}
int op,l,r,k;
signed main(){
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    tim[++tmcnt]=build(1,n);
    while(q--){
        cin>>op;
        if(op==3){
            cin>>k;
            tim[++tmcnt]=tim[k];
        }else if(op==2){
            cin>>k>>l>>r;
            cout<<query(1,n,l,r,tim[k])<<'\n';;
        }else{
            cin>>k>>l>>r;
            tim[k]=modify(1,n,l,r,tim[k]);
        }
    }
}