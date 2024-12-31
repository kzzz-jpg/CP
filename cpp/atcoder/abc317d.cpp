#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,sum=0,ans=1e18;
int x[200],y[200],z[200];
int dp[150][100500];
signed main(){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>x[i]>>y[i]>>z[i],sum+=z[i];
        for(int i=0;i<=n;i++) for(int j=0;j<=sum;j++) dp[i][j]=1e18;
        dp[0][0]=0;
        for(int i=1;i<=n;i++){
                for(int j=0;j<=sum;j++){
                        if(j-z[i]<0) dp[i][j]=dp[i-1][j];
                        else dp[i][j]=min(dp[i-1][j],dp[i-1][j-z[i]]+max(0LL,((x[i]+y[i])/2+1)-x[i]));
                }
        }
        for(int j=sum/2+1;j<=sum;j++) ans=min(ans,dp[n][j]);
        cout<<ans<<'\n';
}
