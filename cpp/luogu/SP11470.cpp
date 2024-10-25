#include<bits/stdc++.h>
using namespace std;
#define int long long
struct nd{
    int l,r,val,lztag;
} tr[2600500];
int n,m,l,r,t;
char op;
int a[100500],tim[100500];
int cnt=0,tmcnt=0,nw=0;
nd cop(int id){
    nd ret=tr[id];
    return ret;
}
int build(int l,int r){
    int nnw=cnt++;
    if(l==r){
        tr[nnw].val=a[l];
        return nnw;
    }
    int mid=(l+r)>>1;
    tr[nnw].l=build(l,mid);
    tr[nnw].r=build(mid+1,r);
    tr[nnw].val=tr[tr[nnw].r].val+tr[tr[nnw].l].val;
    return nnw;
}
int modify(int l,int r,int L,int R,int v,int id){
    int nnw=cnt++;
    tr[nnw]=cop(id);
    if(L<=l&&r<=R){
        tr[nnw].lztag+=v;
        return nnw;
    }
    int mid=(l+r)>>1;
    if(R<=mid)
        tr[nnw].l=modify(l,mid,L,R,v,tr[nnw].l);
    else if(L>mid)
        tr[nnw].r=modify(mid+1,r,L,R,v,tr[nnw].r);
    else{
        tr[nnw].l=modify(l,mid,L,R,v,tr[nnw].l);
        tr[nnw].r=modify(mid+1,r,L,R,v,tr[nnw].r);
    }
    tr[id].val=tr[tr[id].l].val+tr[tr[id].r].val+tr[tr[id].l].lztag*(mid-l+1)+tr[tr[id].r].val*(r-mid);
    return nnw;
}
int query(int l,int r,int L,int R,int id,int nwtag){
    nwtag+=tr[id].lztag;
    if(L<=l&&r<=R){
        return tr[id].val+nwtag*(r-l+1);
    }
    int mid=(l+r)>>1;
    int ret=0;
    if(R<=mid) return ret+query(l,mid,L,R,tr[id].l,nwtag);
    else if(L>mid) return ret+query(mid+1,r,L,R,tr[id].r,nwtag);
    ret+=query(l,mid,L,R,tr[id].l,nwtag)+query(mid+1,r,L,R,tr[id].r,nwtag);
    return ret;
}
signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    nw=0;
    tim[nw]=build(1,n);
    while(m--){
        cin>>op;
        if(op=='Q'){
            cin>>l>>r;
            cout<<query(1,n,l,r,tim[nw],0)<<'\n';
        }else if(op=='B'){
            cin>>t;
            nw=t;
        }else if(op=='C'){
            cin>>l>>r>>t;
            tim[nw+1]=modify(1,n,l,r,t,tim[nw]);
            nw++;
        }else if(op=='H'){
            cin>>l>>r>>t;
            cout<<query(1,n,l,r,tim[t],0)<<'\n';
        }
    }
}