#include<bits/stdc++.h>
#define int long long
using namespace std;
const int P=998244353;
int n,m,k;
int dp[1050][5050];
signed main(){
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++) dp[1][i]=i%P;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=m;j++){
            int l=max(1LL,j-k+1),r=min(m,j+k-1);
            if(k) dp[i][j]=(dp[i-1][m]-(dp[i-1][r]-dp[i-1][l-1]+P+P+P+P+P)%P+P+P+P+P+P)%P;
            else dp[i][j]=dp[i-1][m];
        }
        for(int j=1;j<=m;j++){
            dp[i][j]=(dp[i][j]+dp[i][j-1])%P;
        }
    }
    cout<<dp[n][m]%P<<'\n';
}