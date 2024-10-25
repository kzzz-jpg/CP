#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200050],tr[2000500];
int n,q;
void build(int l,int r,int id){
    if(l==r){
        if(l>n){
            tr[id]=a[l-n]+(l-n-1);
        }else{
            tr[id]=a[l]+(n-l);
        }
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,id<<1);
    build(mid+1,r,id<<1|1);
    tr[id]=min(tr[id<<1],tr[id<<1|1]);
}
void modify(int l,int r,int x,int v,int id){
    if(x<l||x>r) return;
    if(l==r){
        if(x>n){
            tr[id]=v+(l-n-1);
        }else{
            tr[id]=v+(n-l);
        }
        return;
    }
    int mid=(l+r)>>1;
    modify(l,mid,x,v,id<<1);
    modify(mid+1,r,x,v,id<<1|1);
    tr[id]=min(tr[id<<1],tr[id<<1|1]);
}
int query(int l,int r,int L,int R,int id){
    if(L>r||R<l) return 1e15;
    if(L<=l&&r<=R) return tr[id];
    int mid=(l+r)>>1;
    int ret=min(query(l,mid,L,R,id<<1),query(mid+1,r,L,R,id<<1|1));
    return ret;
}
int op,k,x;
signed main(){
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,n<<1,1);
    while(q--){
        cin>>op>>k;
        if(op^2){
            cin>>x;
            modify(1,n<<1,k,x,1);
            modify(1,n<<1,k+n,x,1);
        }else{
            int ll=query(1,n<<1,1,k,1)-(n-k);
            int rr=query(1,n<<1,k+n,n<<1,1)-(k-1);
            cout<<min(ll,rr)<<'\n';
        }
    }
}