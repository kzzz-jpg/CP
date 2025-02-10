#include "bits/stdc++.h"
using namespace std;
#define int long long
int a[200500],b[200500];
int dp[3050][10050][2];
int n,d,ans;
signed main(){
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    //for(int i=0;i<=n;i++) for(int j=0;j<=d;j++) dp[i][j][0]=dp[i][j][1]=-1;
    dp[0][0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=d;j++){
            dp[i][j][0]=max(dp[i-1][j][1],dp[i-1][j][0]);
            if(j-a[i]>=0) {
                dp[i][j][1]=dp[i-1][j-a[i]][0];
                if(dp[i-1][j-a[i]][1]!=-1)
                    dp[i][j][1]=max(dp[i][j][1],dp[i-1][j-a[i]][1]+b[i]);
                if(a[i]>=a[i-1]) dp[i][j][1]=max(dp[i][j][1],dp[i-1][j-a[i]][0]+b[i]);
            }
            ans=max({ans,dp[i][j][0],dp[i][j][1]});
        }
    }
    cout<<ans<<'\n';
}