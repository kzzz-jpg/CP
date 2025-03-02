#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,q,r,x,y;
int hd[1000500],to[1000500],nxt[1000500],cnt=1,dep[500500],top[500500],sz[500500],son[500500],fa[500500];
void addE(int a,int b){
    nxt[cnt]=hd[a];
    to[cnt]=b;
    hd[a]=cnt++;
}
void dfs1(int x,int par,int deep){
    dep[x]=deep;
    fa[x]=par;
    sz[x]=1;
    for(int e=hd[x];e;e=nxt[e]){
        if(to[e]==par) continue;
        dfs1(to[e],x,deep+1);
        sz[x]+=sz[to[e]];
        if(sz[to[e]]>sz[son[x]]) son[x]=to[e];
    }
}
void dfs2(int x,int topf){
    top[x]=topf;
    if(son[x]) dfs2(son[x],topf);
    for(int e=hd[x];e;e=nxt[e]){
        if(to[e]==fa[x]||to[e]==son[x]) continue;
        dfs2(to[e],to[e]);
    }
}
int lca(int a,int b){
    while(top[a]!=top[b]){
        if(dep[top[a]]<dep[top[b]]) swap(a,b);
        a=fa[top[a]];
    }
    if(dep[a]>dep[b]) return b;
    return a;
}
signed main(){
    scanf("%lld%lld%lld",&n,&q,&r);
    for(int i=1;i<n;i++){
        scanf("%lld%lld",&x,&y);
        addE(x,y);
        addE(y,x);
    }
    dfs1(r,r,1);
    dfs2(r,r);
    while(q--){
        scanf("%lld%lld",&x,&y);
        printf("%lld\n",lca(x,y));
    }
}