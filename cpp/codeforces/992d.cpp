#include<bits/stdc++.h>
#define int long long
using namespace std;
bitset<500000> vs;
void era(int ed){
    vs[0]=vs[1]=1;
    for(int i=2;i<=ed;i++){
        if(vs[i]) continue;
        for(int j=i*i;j<=ed;j+=i) vs[j]=1;
    }
}
int n;
int hd[200500],nxt[400500],to[400500];
int ans[200500];
int cnt;
void addE(int a,int b){
    nxt[cnt]=hd[a];
    to[cnt]=b;
    hd[a]=cnt++;
}
int dfn=1;
void dfs(int x,int par){
    ans[x]=dfn++;
    while(!vs[ans[x]-ans[par]]) ans[x]=dfn++;
    for(int e=hd[x];e;e=nxt[e]){
        if(to[e]!=par) dfs(to[e],x);
    }
}
void solve(){
    cnt=1,dfn=1;
    for(int i=1;i<=n;i++) hd[i]=0,ans[i]=0;
    cin>>n;
    int x,y;
    for(int i=1;i<n;i++) cin>>x>>y,addE(x,y),addE(y,x);
    dfs(1,1);
    for(int i=1;i<=n;i++) cout<<ans[i]<<" \n"[i==n];
}
signed main(){
    int t=1;
    era(400500);
    cin>>t;
    while(t--) solve();
}