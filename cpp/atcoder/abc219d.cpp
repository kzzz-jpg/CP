#include<bits/stdc++.h>
using namespace std;
int n,x,y;
int a[310],b[310];
int dp[310][610][610];
int ans=88888888;
int suma,sumb;
signed main(){
    cin>>n>>x>>y;
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i],suma+=a[i],sumb+=b[i];
    //cerr<<suma<<' '<<sumb<<'\n';
    memset(dp,0x3f3f3f,sizeof dp);
    dp[0][0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=600;j++){
            for(int k=0;k<=600;k++) {
                if(j<a[i]||k<b[i]) dp[i][j][k]=dp[i-1][j][k];
                else dp[i][j][k]=min(dp[i-1][j][k],dp[i-1][j-a[i]][k-b[i]]+1);
                if(j>=x&&k>=y) ans=min(ans,dp[i][j][k]);
            }
            for(int k=599;k>=y;k--) dp[i][j][k]=min(dp[i][j][k+1],dp[i][j][k]);
        }
        for(int j=599;j>=x;j--){
            for(int k=0;k<=600;k++) {
                dp[i][j][k]=min(dp[i][j+1][k],dp[i][j][k]);
            }
        }
    }
    for(int j=x;j<=600;j++) for(int k=y;k<=600;k++) ans=min(ans,dp[n][j][k]);
    if(ans==88888888) cout<<-1<<'\n';
    else cout<<ans<<'\n';
}