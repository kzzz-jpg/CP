#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[300500][11];
int dp[300500],dp2[300500];
signed main(){
        ios_base::sync_with_stdio(0),cin.tie(0);
        for(int i=0;i<=300000;i++) dp2[i]=dp[i]=999999;
        cin>>n>>m;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>s[i][j];
        dp[n]=0;
        dp2[1]=0;
        for(int i=2;i<=n;i++){
                for(int j=1;j<=m;j++){
                        if(i-j>=1&&s[i-j][j]=='1') dp2[i]=min(dp2[i],dp2[i-j]+1);
                }
        }
        for(int i=n-1;i;i--){
                for(int j=1;j<=m;j++){
                        if(i+j<=n&&s[i][j]=='1'){
                                dp[i]=min(dp[i],dp[i+j]+1);
                        } 
                }
        }
        /*
        cerr<<"=======================\n";
        for(int i=1;i<=n;i++) cerr<<dp2[i]<<' ';
        cerr<<'\n';
        for(int i=1;i<=n;i++) cerr<<dp[i]<<' ';
        cerr<<'\n';
        cerr<<"======================\n";
        */
        for(int i=2;i<n;i++){
                int ans=999999;
                for(int j=max(i-m,1);j<=i-1;j++){
                        for(int k=i+1;k<=min(n,j+m);k++){
                                if(s[j][k-j]=='1') ans=min(ans,dp2[j]+1+dp[k]);
                        }
                }
                if(ans==999999) cout<<-1<<'\n';
                else cout<<ans<<'\n';
        } 
}
