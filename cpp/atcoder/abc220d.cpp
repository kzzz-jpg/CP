#include<bits/stdc++.h>
using namespace std;
int n,a[200500];
int dp[10][200500];
const int P=998244353;
signed main(){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        dp[a[1]][1]=1;
        for(int i=2;i<=n;i++){
                for(int j=0;j<10;j++){
                        dp[(a[i]*j)%10][i]=(dp[(a[i]*j)%10][i]+dp[j][i-1])%P;
                        dp[(a[i]+j)%10][i]=(dp[(a[i]+j)%10][i]+dp[j][i-1])%P;
                }
        }
        for(int i=0;i<10;i++) cout<<dp[i][n]<<'\n';
}
