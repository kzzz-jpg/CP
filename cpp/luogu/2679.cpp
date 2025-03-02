#include<bits/stdc++.h>
#define CC
#define int long long
using namespace std;
const int P=1e9+7;
int n,m,k,dp[2][201][201][2];
char a[1010],b[210];
signed main(){
    #ifdef CC 
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    freopen("out.out","w",stderr);
    #endif
    scanf("%lld%lld%lld",&n,&m,&k);
    scanf("%s",a+1);
    scanf("%s",b+1);
    for(int i=0;i<=n;i++) dp[i&1][0][0][0]=1;
    //for(int j=0;j<=m;j++) dp[0][j][0][0]=1;
    //dp[0][0][0][0]=1;

    for(int i=1;i<=n;i++){
        memset(dp[i&1],0,sizeof(dp[i&1]));
        dp[i&1][0][0][0]=1;
        for(int j=1;j<=m;j++){
            for(int s=1;s<=k;s++){
                dp[i&1][j][s][0]=(dp[(i^1)&1][j][s][0]+dp[(i^1)&1][j][s][1])%P;
                if(a[i]==b[j]){
                    dp[i&1][j][s][1]=(dp[(i^1)&1][j-1][s-1][0]+dp[(i^1)&1][j-1][s-1][1]+dp[(i^1)&1][j-1][s][1])%P;
                    //cerr<<dp[i-1][j-1][s-1][0]<<' '<<dp[i-1][j-1][s][1]<<'\n';
                }
                //cerr<<"i= "<<i<<' '<<"j= "<<j<<" k= "<<s<<' '<<"dp= "<<dp[i&1][j][s][0]<<' '<<dp[i&1][j][s][1]<<'\n';
            }
        }
    }
    cout<<(dp[n&1][m][k][0]+dp[n&1][m][k][1])%P<<'\n';
}