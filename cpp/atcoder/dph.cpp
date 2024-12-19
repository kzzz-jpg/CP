#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[1010][1010];
char g[1010][1010];
int n,m;
const int P=1e9+7;
signed main(){
        cin>>n>>m,dp[1][1]=1;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>g[i][j];
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(g[i][j]=='.')dp[i][j]+=dp[i-1][j]+dp[i][j-1],dp[i][j]%=P;
        cout<<dp[n][m]<<'\n';
}
