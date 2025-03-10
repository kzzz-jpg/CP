#include<bits/stdc++.h>
#include <ios>
using namespace std;
int a[50050];
int mn[200500],mx[200500],n,q;
void build(int l,int r,int id){
    if(l==r) {
        mn[id]=a[l];
        mx[id]=a[l];
        return;
    }
    int mid=l+r>>1;
    build(l,mid,id<<1);
    build(mid+1,r,id<<1|1);
    mn[id]=min(mn[id<<1],mn[id<<1|1]);
    mx[id]=max(mx[id<<1],mx[id<<1|1]);
}
pair<int,int> query(int l,int r,int L,int R,int id){
    if(l>R||r<L) return {0,1e9};
    if(L<=l&&r<=R) return {mx[id],mn[id]};
    int mid=l+r>>1;
    auto ret1=query(l,mid,L,R,id<<1),ret2=query(mid+1,r,L,R,id<<1|1);
    ret1.first=max(ret1.first,ret2.first);
    ret1.second=min(ret2.second,ret1.second);
    return ret1;
}
signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,n,1);
    int l,r;
    while(q--){
        cin>>l>>r;
        auto ans=query(1,n,l,r,1);
        cout<<ans.first-ans.second<<'\n';
    }
}