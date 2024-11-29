#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
struct ln{
        int a,b;
        bool operator < (ln o) const{
                return a*o.b+b<o.a*b+o.b;
        }
} l[200500];
int dp[200500][11];
signed main(){
        cin>>n>>k;
        for(int i=1;i<=n;i++) cin>>l[i].a>>l[i].b;
        sort(l+1,l+1+n);
        for(int i=0;i<=n;i++) dp[i][0]=1;
        for(int i=1;i<=n;i++){
                for(int j=1;j<=k;j++){
                        dp[i][j]=max(dp[i-1][j],l[i].a*dp[i-1][j-1]+l[i].b);
                }
        }
        cout<<dp[n][k]<<'\n';
}
