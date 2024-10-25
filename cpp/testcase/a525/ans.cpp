#include<bits/stdc++.h>
using namespace std;
#define int long long
int fa[400500],sz[400500];
int n,m;
int find(int x){
    if(fa[x]==x) return x;
    return find(fa[x]);
}
void cb(int a,int b){
    a=find(a),b=find(b);
    if(a==b) return;
    if(sz[a]>sz[b]) swap(a,b);
    fa[a]=b;
    sz[b]+=sz[a];
}
bool chk(int x,int y){
    x=find(x),y=find(y);
    return x==y;
}
int l,r;
signed main(){
    cin>>n>>m;
    for(int i=1;i<=2*n;i++) fa[i]=i,sz[i]=1;
    for(int i=0;i<m;i++) cin>>l>>r,cb(l,r+n),cb(r,l+n);
    for(int i=1;i<=n;i++){
        if(chk(i,i+n)){
            cout<<0<<'\n';
            return 0;
        }
    }
    cout<<1<<'\n';
    return 0;
}