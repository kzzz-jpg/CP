#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[1000001],b[1000001];
int dp[1000001][3],opt[1000001][3],dp2[1000001][3],opt2[1000001][3];
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    dp[1][0]=a[1];
    dp[1][1]=b[1];
    dp[1][2]=-1e15;
    for(int i=2;i<=n;i++){
        dp[i][0]=dp[i-1][0]+a[i];
        if(dp[i-1][1]>dp[i-1][0]){
            dp[i][1]=dp[i-1][1]+b[i];
            opt[i][1]=1;
        }else{
            dp[i][1]=dp[i-1][0]+b[i];
            opt[i][1]=0;
        }
        if(dp[i-1][2]>dp[i-1][1]){
            dp[i][2]=dp[i-1][2]+a[i];
            opt[i][2]=2;
        }else{
            dp[i][2]=dp[i-1][1]+a[i];
            opt[i][2]=1;
        }
    }
    dp2[1][0]=b[1];
    dp2[1][1]=a[1];
    dp2[1][2]=-1e15;
    for(int i=2;i<=n;i++){
        dp2[i][0]=dp2[i-1][0]+b[i];
        if(dp2[i-1][1]>dp2[i-1][0]){
            dp2[i][1]=dp2[i-1][1]+a[i];
            opt2[i][1]=1;
        }else{
            dp2[i][1]=dp2[i-1][0]+a[i];
            opt2[i][1]=0;
        }
        if(dp2[i-1][2]>dp2[i-1][1]){
            dp2[i][2]=dp2[i-1][2]+b[i];
            opt2[i][2]=2;
        }else{
            dp2[i][2]=dp2[i-1][1]+b[i];
            opt2[i][2]=1;
        }
    }
    if(max({dp[n][0],dp[n][1],dp[n][2]})>max({dp2[n][0],dp2[n][1],dp2[n][2]})){
        if(dp[n][0]>dp[n][1]&&dp[n][0]>dp[n][2]){
            cout<<dp[n][0]<<' '<<-1<<' '<<-1<<'\n';
        }else if(dp[n][1]>dp[n][2]&&dp[n][1]>dp[n][0]){
            int ans;
            for(int i=n;i>=0;i--){
                if(opt[i][1]==0) {
                    ans=i;
                    break;
                }
            }
            cout<<dp[n][1]<<' '<<ans<<' '<<n<<'\n';
        }else{
            int ans1,ans2;
            for(int i=n;i>=0;i--){
                if(opt[i][2]==1){
                    ans2=i-1;
                    break;
                }
            }
            for(int i=ans2;i>=0;i--){
                if(opt[i][1]==0){
                    ans1=i;
                break;
                }
            }
            cout<<dp[n][2]<<' '<<ans1<<' '<<ans2<<'\n';
        }
    }else{
        if(dp2[n][0]>dp2[n][1]&&dp2[n][0]>dp2[n][2]){
            cout<<dp2[n][0]<<' '<<-1<<' '<<-1<<'\n';
        }else if(dp2[n][1]>dp2[n][2]&&dp2[n][1]>dp2[n][0]){
            int ans;
            for(int i=n;i>=0;i--){
                if(opt2[i][1]==0) {
                    ans=i;
                    break;
                }
            }
            cout<<dp2[n][1]<<' '<<ans<<' '<<n<<'\n';
        }else{
            int ans1,ans2;
            for(int i=n;i>=0;i--){
                if(opt2[i][2]==1){
                    ans2=i-1;
                    break;
                }
            }
            for(int i=ans2;i>=0;i--){
                if(opt2[i][1]==0){
                    ans1=i;
                break;
                }
            }
            cout<<dp2[n][2]<<' '<<ans1<<' '<<ans2<<'\n';
        }
    }
}