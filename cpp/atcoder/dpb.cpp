#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,dp[200500],h[200500];
signed main(){
        cin>>n>>k;
        for(int i=1;i<=n;i++) cin>>h[i],dp[i]=88888888888;
        dp[1]=0;
        for(int i=2;i<=n;i++){
                for(int j=1;i-j>=1&&j<=k;j++){
                        dp[i]=min(dp[i],dp[i-j]+abs(h[i]-h[i-j]));
                }
        }
        cout<<dp[n]<<'\n';
}
