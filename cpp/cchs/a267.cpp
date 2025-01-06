#include<bits/stdc++.h>
#define int long long
using namespace std;
int dp[100500][105];
int a[200500],b[200];
int ans,n,k;
signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>k;
    n--;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=k;i++) cin>>b[i];
    sort(b+1,b+1+k,greater<int>());
    for(int i=1;i<=n;i++) dp[i][0]=max(0LL,dp[i-1][0]+a[i]),ans=max(ans,dp[i][0]);
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            dp[j][i]=max({0LL,dp[j-1][i-1]+b[i],dp[j-1][i]+a[j]});
            ans=max(ans,dp[j][i]);
        }
    }
    cout<<ans<<'\n';
}