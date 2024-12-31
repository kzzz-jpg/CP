#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[200500];
int dp[3050][3050];
int ans=0;
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=2;i<=n;i++){
        for(int j=1;i-j>=1;j++){
            if(a[i]==a[i-j]){
                dp[i][j]=max(dp[i][j],dp[i-j][j]+1);
            }
            ans=max(ans,dp[i][j]);
           // cerr<<dp[i][j]<<' ';
        }
       // cerr<<'\n';
    }
    cout<<ans+1<<'\n';
}