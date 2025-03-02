#include<bits/stdc++.h>
#define CP
#define int long long
using namespace std;
int n,s,t,ans;
int hd[200500],to[200500],nxt[200500],sz[200500],fa[200500],dep[200500],son[200500],top[200500],cnt=1;
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
        if(to[e]!=par){
            dfs1(to[e],x,deep+1);
            sz[x]+=sz[to[e]];
            if(sz[to[e]]>sz[son[x]]){
                son[x]=to[e];
            }
        }
    }
}
void dfs2(int x,int topf){
    top[x]=topf;
    if(son[x]) dfs2(son[x],topf);
    for(int e=hd[x];e;e=nxt[e]){
        if(to[e]!=fa[x]&&to[e]!=son[x]){
            dfs2(to[e],to[e]);
        }
    }
}
int lca(int a,int b){
    while(top[a]!=top[b]){
        if(dep[top[a]]<dep[top[b]]) swap(a,b);
        a=fa[top[a]];
    }
    if(dep[a]<dep[b]) return a;
    return b;
}
int dis(int a,int b){
    return dep[a]+dep[b]-2*dep[lca(a,b)];
}
signed main(){
    #ifdef CP 
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    freopen("err.out","w",stderr);
    #endif
    scanf("%lld%lld%lld",&n,&s,&t);
    int x,y;
    for(int i=1;i<n;i++){
        scanf("%lld%lld",&x,&y);
        addE(x,y);
        addE(y,x);
    }
    dfs1(1,1,1);
    dfs2(1,1);
    for(int i=1;i<=n;i++){
        int tmpa=dis(i,s),tmpb=dis(i,t);
        if(tmpa<tmpb){
            ans=max(ans,tmpb-1);
        }
    }
    printf("%lld",ans);
}