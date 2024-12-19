#include<bits/stdc++.h>
#define int long long
using namespace std;
int hd[200500],nxt[400500],to[400500];
int a[200500],dep[200500],top[400500],id[200500],w[200500],fa[200500],sz[200500],son[200500];
int cnt=1,n,r,q,p;
int ans=0;
void addE(int a,int b){
        nxt[cnt]=hd[a];
        to[cnt]=b;
        hd[a]=cnt++;
}
void dfs(int x,int par,int dp){
        dep[x]=dp;
        fa[x]=par;
        sz[x]=1;
        int mx=-1;
        for(int e=hd[x];e;e=nxt[e]){
                if(to[e]==fa[x]) continue;
                dfs(to[e],x,dp+1);
                sz[x]+=sz[to[e]];
                if(sz[to[e]]>mx) son[x]=to[e],mx=sz[to[e]];
        }
}
void dfs2(int x,int topf){
        if(x==topf) ans++;
        id[x]=++cnt;
        w[cnt]=a[x];
        top[x]=topf;
        if(!son[x]) return;
        dfs2(son[x],topf);
        for(int e=hd[x];e;e=nxt[e]) if(to[e]!=fa[x]&&to[e]!=son[x]) dfs2(to[e],to[e]);
}
signed main(){
        cin>>n;
        int x,y;
        for(int i=1;i<n;i++) cin>>x>>y,addE(x,y);
        dfs(1,1,1);
        dfs2(1,1);
        cout<<ans<<'\n';
}
