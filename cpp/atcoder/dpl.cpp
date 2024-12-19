#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int dp[3010][3010];
signed main(){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>dp[i][i];
        for(int i=1;i<=n;i++){
                for(int l=1,r=l+i;r<=n;r++,l++){
                        dp[l][r]=max(dp[l][l]-dp[l+1][r],dp[r][r]-dp[l][r-1]);
                }
        }
        cout<<dp[1][n]<<'\n';
}
