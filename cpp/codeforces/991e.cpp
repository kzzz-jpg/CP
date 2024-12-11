#include<bits/stdc++.h>
using namespace std;
void solve(){
        string a,b,c;
        cin>>a>>b>>c;
        a=" "+a,b=" "+b,c=" "+c;
        vector<vector<int>> dp(a.size()+1,vector<int>(b.size()+1));
        for(int i=1;i<a.size();i++) dp[i][0]=dp[i-1][0]+(a[i]!=c[i]);
        for(int i=1;i<b.size();i++) dp[0][i]=dp[0][i-1]+(b[i]!=c[i]);
        for(int i=1;i<a.size();i++){
                for(int j=1;j<b.size();j++){
                        dp[i][j]=min(dp[i][j-1]+(b[j]!=c[i+j]),dp[i-1][j]+(a[i]!=c[i+j]));
                }
        }
        /*
        for(int i=0;i<a.size();i++){
                for(int j=0;j<b.size();j++) cerr<<dp[i][j]<<' ';
                cerr<<'\n';
        }
        */
        cout<<dp[a.size()-1][b.size()-1]<<'\n';
}
signed main(){
        int t=1;
        cin>>t;
        while(t--) solve();
}
