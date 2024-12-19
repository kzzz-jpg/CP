#include<bits/stdc++.h>
using namespace std;
int n;
double dp[3000][3000];
double p[3000];
signed main(){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>p[i];
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
                dp[i][0]=dp[i-1][0]*(1-p[i]);
                for(int j=1;j<=n;j++){
                        dp[i][j]=dp[i-1][j]*(1-p[i])+dp[i-1][j-1]*p[i];
                }
        }
        double ans=0;
        for(int i=n/2+1;i<=n;i++) ans+=dp[n][i];
        cout<<fixed<<setprecision(12)<<ans<<'\n';
}
