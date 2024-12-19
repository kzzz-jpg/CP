#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
int w[200500],v[200500];
int dp[200][200500];
signed main(){
        for(int i=0;i<=150;i++) for(int j=0;j<=100500;j++) dp[i][j]=8888888888888;
        cin>>n>>k;
        for(int i=1;i<=n;i++) cin>>w[i]>>v[i];
        dp[0][0]=0;
        for(int i=1;i<=n;i++){
                for(int j=0;j<=100500;j++){
                        dp[i][j]=dp[i-1][j];
                        if(j-v[i]>=0) dp[i][j]=min(dp[i-1][j-v[i]]+w[i],dp[i][j]);
                }
        }
        for(int i=100500;i>=0;i--){
                if(dp[n][i]<=k) return cout<<i<<'\n',0;
        }
}
