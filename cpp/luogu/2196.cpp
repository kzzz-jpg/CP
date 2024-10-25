#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[21];
int g[21][21];
int dp[21];
int fa[21];
void dfs(int x,int d,int par){
    if(d+a[x]>dp[x]) {
        dp[x]=max(dp[x],d+a[x]);
        fa[x]=par;
    }
    for(int i=x+1;i<=n;i++){
        if(g[x][i]) dfs(i,d+a[x],x);
    }
}
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        g[0][i]=1;
        for(int j=i+1;j<=n;j++){
            cin>>g[i][j];
        }
    }
    dfs(0,0,0);
    vector<int> res;
    int nw=0;
    for(int i=1;i<=n;i++){
        if(dp[i]>dp[nw]) nw=i;
    }
    int nww=nw;
    while(nw){
        res.push_back(nw);
        nw=fa[nw];
    }
    for(auto it=res.end();it>=res.begin();it--)
    for(auto it=res.rbegin();it!=res.rend();it++)
    cout<<*it<<' ';
    cout<<'\n';
    cout<<dp[nww]<<'\n';
}