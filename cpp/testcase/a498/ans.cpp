#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,dp[210][210],ans;
signed main(){
  scanf("%lld",&n);
  for(int i=1;i<=n;i++) scanf("%lld",&dp[i][i]),ans=max(ans,dp[i][i]);
  for(int i=1;i<=n;i++){
    for(int l=1,r=1+i;r<=n;l++,r++){
      for(int k=l;k+1<=r;k++){
        if(dp[l][k]==dp[k+1][r]){
          dp[l][r]=max(dp[l][r],dp[l][k]+dp[k+1][r]);
          ans=max(ans,dp[l][r]);
        }
      }
    }
  }
  printf("%lld\n",ans);
}
