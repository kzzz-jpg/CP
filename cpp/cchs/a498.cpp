#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[200][200];
int n,ans=0;
int32_t main(){
    for(int i=0;i<200;i++){
        for(int j=0;j<200;j++) dp[i][j]=0;
    }
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>dp[i][i],ans=max(ans,dp[i][i]);
    }
    for(int i=1;i<=n;i++){
        for(int l=1,r=l+i;r<=n;l++,r++){
            for(int k=l;k<r;k++){
                if(dp[l][k]&&dp[l][k]==dp[k+1][r]){
                  //  cerr<<l<<' '<<k<<' '<<r<<' '<<dp[l][k]<<' '<<dp[k+1][r]<<' ';
                    dp[l][r]=dp[l][k]+dp[k+1][r];
                    assert(dp[l][k]+dp[k+1][r]>=0);
                    ans=max(ans,dp[l][r]);
                   // cerr<<dp[l][r]<<'\n';
                }
            }
        }
    }
    cout<<ans<<'\n';
}