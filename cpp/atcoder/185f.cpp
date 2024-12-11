#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[300500],tr[1200500];
int n,q;
void build(int l,int r,int id){
        if(l==r){
                tr[id]=a[l];
                return;
        }
        int mid=l+r>>1;
        build(l,mid,id<<1);
        build(mid+1,r,id<<1|1);
        tr[id]=tr[id<<1]^tr[id<<1|1];
}
int query(int l,int r,int L,int R,int id){
        if(l>R||r<L){
                return 0;
        }
        if(L<=l&&r<=R) return tr[id];
        int mid=l+r>>1;
        return query(l,mid,L,R,id<<1)^query(mid+1,r,L,R,id<<1|1);
}
void modify(int l,int r,int pos,int v,int id){
        if(l==r){
                tr[id]^=v;
                return;
        }
        int mid=l+r>>1;
        if(pos<=mid) modify(l,mid,pos,v,id<<1);
        else modify(mid+1,r,pos,v,id<<1|1);
        tr[id]=tr[id<<1]^tr[id<<1|1];
}
signed main(){
        cin>>n>>q;
        for(int i=1;i<=n;i++) cin>>a[i];
        build(1,n,1);
        int op,x,y;
        while(q--){
                cin>>op>>x>>y;
                if(op==1){
                        modify(1,n,x,y,1);
                }else{
                        cout<<query(1,n,x,y,1)<<'\n';
                }
        }
}
