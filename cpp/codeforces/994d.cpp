#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
    int n,m,c;
    cin>>n>>m>>c;
    vector<vector<int>> dp(n,vector<int>(m,1e18)),g(n,vector<int>(m));
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>g[i][j];
    dp[0][0]=g[0][0];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(j) dp[i][j]=min(dp[i][j-1]+g[i][j],dp[i][j]);
            if(i){
                for(int k=0;k<m;k++){
                    dp[i][j]=min(dp[i-1][k]+((k-j+m)%m)*c+g[i][j],dp[i][j]);
                }
            }
            cerr<<dp[i][j]<<' ';
        }
        cerr<<'\n';
    }
    cerr<<'\n';
    int ans=1e18;
    for(int i=0;i<m;i++){
        ans=min(ans,dp[n-1][i]+((i+1)%m)*c);
    }
    cout<<ans<<'\n';
}
signed main(){
    int t=1;
    cin>>t;
    while(t--)solve();
}