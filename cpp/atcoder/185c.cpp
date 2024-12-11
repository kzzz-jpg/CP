#include<bits/stdc++.h>
#define int long long
using namespace std;
int dp[20][300];
int l;
signed main(){
        cin>>l;
        for(int i=1;i<l;i++) dp[1][i]=1;
        for(int i=2;i<=11;i++){
                for(int j=i;j<=l-1;j++){
                        for(int k=0;k<j;k++){
                                dp[i][j]+=dp[i-1][k];
                        }
          //              cerr<<dp[i][j]<<' ';
                }
        //        cerr<<'\n';
        }
        int ans=0;
        for(int i=1;i<=l;i++) ans+=dp[11][i];
        cout<<ans<<'\n';
}
