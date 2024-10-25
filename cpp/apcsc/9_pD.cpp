#include<bits/stdc++.h>
#include<random>
using namespace std;
#define int long long
int dp[1001][11][11][11];
int a,b;
int n,m,q[20],ans=1e18;
pair<int,int> p[1010];
void init(){
    for(int i=0;i<n;i++)
        for(int j=1;j<=m;j++)
            for(int k=1;k<=m;k++)
                for(int l=1;l<=m;l++)
                    dp[i][j][k][l]=-1;
}
int dfs(int i,int f,int s,int t){
    if(i==n-1) return min({abs(q[p[i].first]-q[f])+abs(q[p[i].second]-q[p[i].first]),abs(q[p[i].first]-q[s])+abs(q[p[i].second]-q[p[i].first]),abs(q[p[i].first]-q[t])+abs(q[p[i].second]-q[p[i].first])});
    if(dp[i][f][s][t]!=-1) return dp[i][f][s][t];
    int ret1,ret2,ret3;
    ret1=dfs(i+1,p[i].second,s,f)+abs(q[p[i].first]-q[f])+abs(q[p[i].second]-q[p[i].first]);
    ret2=dfs(i+1,f,p[i].second,f)+abs(q[p[i].first]-q[s])+abs(q[p[i].second]-q[p[i].first]);
    ret3=dfs(i+1,f,s,p[i].second)+abs(q[p[i].first]-q[t])+abs(q[p[i].second]-q[p[i].first]);
    return dp[i][f][s][t]=min({ret1,ret2,ret3});
}
void solve(){
    cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>p[i].first>>p[i].second;
	}
	for(int i=1;i<=m;i++)cin>>q[i];
    init();
    cout<<dfs(0,1,1,1);
}
signed main(){
    int t=1;
    while(t--) solve();
}