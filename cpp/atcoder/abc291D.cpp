#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
const int P=998244353;
int ans=1;
struct cd{
    int l,r;
} a[200500];
int dp[200500][2];
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].l>>a[i].r;
    dp[1][0]=dp[1][1]=1;
    for(int i=2;i<=n;i++){
        if(a[i].l!=a[i-1].l) dp[i][0]=(dp[i][0]+dp[i-1][0])%P;
        if(a[i].l!=a[i-1].r) dp[i][0]=(dp[i][0]+dp[i-1][1])%P;
        if(a[i].r!=a[i-1].r) dp[i][1]=(dp[i][1]+dp[i-1][1])%P;
        if(a[i].r!=a[i-1].l) dp[i][1]=(dp[i][1]+dp[i-1][0])%P;
    }
    cout<<(dp[n][0]+dp[n][1])%P<<'\n';
}