#include<bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
int a[50050],pos[50050],mn[500],mx[500],kui,bkcnt;
int n,q;
int qryMin(int l,int r){
    int ret=1e9;
    if(pos[l]==pos[r]){
        for(int i=l;i<=r;i++) ret=min(ret,a[i]);
        return ret;
    }
    for(int i=l;i<=pos[l]*kui;i++) ret=min(ret,a[i]);
    for(int i=(pos[r]-1)*kui+1;i<=r;i++) ret=min(ret,a[i]);
    for(int i=pos[l]+1;i<=pos[r]-1;i++) ret=min(ret,mn[i]);
    return ret;
}
int qryMax(int l,int r){
    int ret=0;
    if(pos[l]==pos[r]){
        for(int i=l;i<=r;i++) ret=max(ret,a[i]);
        return ret;
    }
    for(int i=l;i<=pos[l]*kui;i++) ret=max(ret,a[i]);
    for(int i=(pos[r]-1)*kui+1;i<=r;i++) ret=max(ret,a[i]);
    for(int i=pos[l]+1;i<=pos[r]-1;i++) ret=max(ret,mx[i]);
    return ret;
}
signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin>>n>>q;
    kui=sqrt(n)+10;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pos[i]=(i-1)/kui+1;
    }
    bkcnt=(n+kui-1)/kui;
    for(int i=1;i<=bkcnt;i++){
        mn[i]=1e9;
        for(int j=(i-1)*kui+1;j<=min(n,i*kui);j++){
            mn[i]=min(mn[i],a[j]);
            mx[i]=max(mx[i],a[j]);
        }
    }
    int l,r;
    while(q--){
        cin>>l>>r;
        cout<<qryMax(l,r)-qryMin(l,r)<<'\n';
    }
}