#include<bits/stdc++.h>
#define int long long
using namespace std;
int dp[510][510];
int n;
int a[200500],p[200500];
int dfs(int u,int v){
   // cerr<<u<<' '<<v<<'\n';
    if(u==v) return 0;
    if(dp[u][v]!=-1) return dp[u][v];
    int ret=1e18;
    for(int i=v;i<u;i++){
        ret=min(ret,dfs(u-1,i)+dfs(i,v)+abs(p[u]-p[i]));
    }
    return dp[u][v]=ret;
}
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],p[a[i]]=i;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) dp[i][j]=-1;
    }
    cout<<dfs(n,1)<<'\n';
}