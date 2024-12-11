#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[2000],b[2000];
int dp[2000][2000];
signed main(){
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int j=1;j<=m;j++) cin>>b[j];
        for(int i=1;i<=n;i++) dp[i][0]=i;
        for(int i=1;i<=m;i++) dp[0][i]=i;
        for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                        dp[i][j]=min({dp[i-1][j-1]+(a[i]!=b[j]),dp[i-1][j]+1,dp[i][j-1]+1});
                }
        }
        cout<<dp[n][m]<<'\n';
}
