#include<bits/stdc++.h>
#define int long long
using namespace std;
int dp[150][200500];
int w[200],v[200];
int n,k;
signed main(){
        cin>>n>>k;
        for(int i=1;i<=n;i++) cin>>w[i]>>v[i];
        for(int i=1;i<=n;i++){
                for(int j=0;j<=k;j++){
                        dp[i][j]=dp[i-1][j];
                        if(j-w[i]>=0) dp[i][j]=max(dp[i][j],dp[i-1][j-w[i]]+v[i]);
                }
        }
        cout<<dp[n][k]<<'\n';
}
