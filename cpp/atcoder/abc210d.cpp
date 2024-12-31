#include<bits/stdc++.h>
#define int long long
using namespace std;
int h,w,c,ans=8e18;
int g[1050][1050],dp[1050][1050][2];
signed main(){
    cin>>h>>w>>c;
    for(int i=1;i<=h;i++) for(int j=1;j<=w;j++) cin>>g[i][j];
    for(int i=0;i<=h;i++) for(int j=0;j<=w;j++) dp[i][j][0]=dp[i][j][1]=7e18;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            dp[i][j][0]=min({dp[i-1][j][0],dp[i-1][j][1],dp[i][j-1][0],dp[i][j-1][1]})+c;
            dp[i][j][1]=g[i][j];
            ans=min(ans,dp[i][j][0]+g[i][j]);
        }
    }
    for(int i=0;i<=h;i++) for(int j=0;j<=w;j++) dp[i][j][0]=dp[i][j][1]=7e18;
    for(int i=1;i<=h;i++) reverse(g[i]+1,g[i]+1+w);
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            dp[i][j][0]=min({dp[i-1][j][0],dp[i-1][j][1],dp[i][j-1][0],dp[i][j-1][1]})+c;
            dp[i][j][1]=g[i][j];
            ans=min(ans,dp[i][j][0]+g[i][j]);
        }
    }
    cout<<ans<<'\n';
}