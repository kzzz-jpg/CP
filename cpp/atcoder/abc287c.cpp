#include<bits/stdc++.h>
using namespace std;
int n,m,lt;
int deg[200500];
int one=0,two=0;
int fa[200500],sz[200500];
int find(int x){
        if(fa[x]==x) return x;
        return fa[x]=find(fa[x]);
}
void cb(int a,int b){
        a=find(a),b=find(b);
        if(a==b)return;
        if(sz[a]>sz[b]) swap(a,b);
        fa[a]=b;
        sz[b]+=sz[a];
        lt--;
}
signed main(){
        int x,y;
        cin>>n>>m;
        lt=n;
        for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
        for(int i=1;i<=m;i++) cin>>x>>y,cb(x,y),deg[x]++,deg[y]++;
        for(int i=1;i<=n;i++) if(deg[i]==2) two++;else if(deg[i]==1) one++;
        if(one==2&&two==n-2&&lt==1) cout<<"Yes\n";
        else cout<<"No\n";
}
