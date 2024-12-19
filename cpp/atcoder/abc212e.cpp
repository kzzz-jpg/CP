#include<bits/stdc++.h>
#define int long long
using namespace std;
const int P=998244353;
int dp[5050][5050];
int hd[200500],to[200500],nxt[200500];
int cnt=1;
void addE(int a,int b){
        nxt[cnt]=hd[a];
        to[cnt]=b;
        hd[a]=cnt++;
}
int n,m,k;
int x,y;
signed main(){
        cin>>n>>m>>k;
        for(int i=0;i<m;i++) cin>>x>>y,addE(x,y),addE(y,x);
        dp[0][1]=dp[0][0]=1;
        for(int i=1;i<=k;i++){
                for(int j=1;j<=n;j++){
                        dp[i][j]=dp[i-1][0];
                        dp[i][j]=(dp[i][j]+P-dp[i-1][j])%P;
                        for(int e=hd[j];e;e=nxt[e]){
                                dp[i][j]=(dp[i][j]+P-dp[i-1][to[e]])%P;
                        }
                        dp[i][0]+=dp[i][j];
                        dp[i][0]%=P;
                }
        }
        cout<<dp[k][1]<<'\n';
}
