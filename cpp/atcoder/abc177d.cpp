#include<bits/stdc++.h>
using namespace std;
int n,m,sz[200500],fa[200500];
int ans=1;
int find(int x){
        if(fa[x]==x) return x;
        return fa[x]=find(fa[x]);
}
void cb(int a,int b){
        a=find(a),b=find(b);
        if(a==b) return;
        if(sz[a]>sz[b]) swap(a,b);
        fa[a]=b;
        sz[b]+=sz[a];
        ans=max(ans,sz[b]);
}
signed main(){
        cin>>n>>m;
        for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
        int x,y;
        for(int i=0;i<m;i++){
                cin>>x>>y;
                cb(x,y);
        }
        cout<<ans<<'\n';
}
