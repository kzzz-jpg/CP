#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[5001][5001];
bool isr[5001][5001];
int n,q;
char s[5001];
int l,r;
signed main(){
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>s[i],dp[i][i]=1,isr[i][i]=1;
    for(int ran=1;ran<=n;ran++){
        for(int a=1,b=ran+1;b<=n;a++,b++){
            dp[a][b]=dp[a][b-1]+dp[a+1][b];
            if(a+1<=b-1){
                dp[a][b]-=dp[a+1][b-1];
                if(s[a]==s[b]&&isr[a+1][b-1]){
                    isr[a][b]=1;
                    dp[a][b]++;
                }
            }else{
                if(s[a]==s[b]){
                    isr[a][b]=1;
                    dp[a][b]++;
                }
            }
        }
    }
    while(q--){
        cin>>l>>r;
        cout<<dp[l][r]<<'\n';
    }
}