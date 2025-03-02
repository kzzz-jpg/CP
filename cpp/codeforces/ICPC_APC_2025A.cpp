#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans;
char g[2010][2010];
int dp[4][2010][2010],prec[2010][2010],prer[2010][2010];
signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>g[i][j];
            if(g[i][j]=='.') dp[0][i][j]=1;
        }
    }
    for(int i=1;i<=3;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=m;k++){
                prer[j][k]=prer[j][k-1]+dp[i-1][j][k];
            }
        }
        for(int j=1;j<=m;j++){
            for(int k=1;k<=n;k++){
                prec[k][j]=prec[k-1][j]+dp[i-1][k][j];
            }
        }
        for(int j=1;j<=n;j++){
            for(int k=1;k<=m;k++){
                if(g[j][k]=='.'){
                    dp[i][j][k]=prer[j][m]+prec[n][k];
                    for(int f=0;f<i;f++) dp[i][j][k]-=dp[f][j][k];
                    dp[i][j][k]-=dp[i-1][j][k];
                }
            }
        }
    }
    for(int i=0;i<4;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=m;k++){
                cerr<<dp[i][j][k]<<' ';
            }
            cerr<<'\n';
        }
        cerr<<'\n';
    }
    for(int j=1;j<=n;j++){
        for(int k=1;k<=m;k++){
            ans+=dp[3][j][k];
        }
    }
    printf("%lld",ans);
}