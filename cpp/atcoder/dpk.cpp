#include<bits/stdc++.h>
using namespace std;
int a[500];
int dp[100500][2]; // 0 for last, 1 for first
int n,k;
signed main(){
        cin>>n>>k;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=0;i<=k;i++) dp[i][0]=1;
        for(int i=a[1];i<=k;i++){
                for(int j=1;j<=n;j++){
                        if(a[j]>i) break;
                        dp[i][0]=min(dp[i-a[j]][1],dp[i][0]);
                        dp[i][1]=max(dp[i-a[j]][0],dp[i][1]);
                }
        }
        //for(int i=0;i<=k;i++) cerr<<dp[i][0]<<" \n"[i==k];
        //for(int i=0;i<=k;i++)cerr<<dp[i][1]<<" \n"[i==k];
        if(dp[k][1]) cout<<"First\n";
        else cout<<"Second\n";
}
