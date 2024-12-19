#include<bits/stdc++.h>
using namespace std;
int n,a[200500],b[200500],c[200500];
int dp[200500][3];
signed main(){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
        for(int i=1;i<=n;i++){
                dp[i][0]=max(dp[i-1][1],dp[i-1][2])+a[i];
                dp[i][1]=max(dp[i-1][2],dp[i-1][0])+b[i];
                dp[i][2]=max(dp[i-1][0],dp[i-1][1])+c[i];
        }
        cout<<max({dp[n][0],dp[n][1],dp[n][2]})<<'\n';
}
