#include<bits/stdc++.h>
#define int long long
using namespace std;
int dp[30][2000];
const int P=998244353;
int fp(int x,int y=P-2){
        int ret=1;
        while(y){
                if(y&1) ret=(ret*x)%P;
                x=(x*x)%P;
                y>>=1;
        }
        return ret;
}
int fac[1050],fpc[1050];
int n,a[30];
signed main(){
        cin>>n;
        fac[0]=fpc[0]=1;
        for(int i=1;i<=1000;i++) fac[i]=fac[i-1]*i%P;
        for(int i=1;i<=1000;i++) fpc[i]=fp(fac[i]);
        for(int i=1;i<=26;i++) cin>>a[i],dp[i][0]=1;
        dp[0][0]=1;
        for(int i=1;i<=26;i++){
                for(int j=1;j<=n;j++){
                        dp[i][j]=dp[i-1][j];
                        for(int k=1;k<=min(j,a[i]);k++){
                                dp[i][j]=(dp[i][j]+dp[i-1][j-k]%P*fac[j]%P*fpc[j-k]%P*fpc[k]%P)%P;
                        }
                        //cerr<<dp[i][j]<<' ';
                }
                //cerr<<'\n';
        }
        int ans=0;
        for(int i=1;i<=n;i++) ans=(ans+dp[26][i])%P;
        cout<<ans<<'\n';
}
