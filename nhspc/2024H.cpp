#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,l,r;
int dp[500500][2];
signed main(){
    cin>>n>>l>>r;
    string s;
    cin>>s;
    for(int i=2;i<n;i++){
        if(s[i]=='.') dp[i][0]=dp[i-1][0],dp[i][1]=dp[i-1][1];
        else if(s[i-1]=='.'){
            dp[i][0]=min(dp[i-1][0]+l*(s[i-2]!=s[i]&&s[i-2]!='.'),dp[i-1][1]);
            dp[i][1]=min(dp[i-1][1]+r*(s[i-2]!=s[i]&&s[i-2]!='.'),dp[i-1][0]);
        }else{
            dp[i][0]=dp[i-1][1]+l*(s[i]!=s[i-2]&&s[i-2]!='.');
            dp[i][1]=dp[i-1][0]+r*(s[i]!=s[i-2]&&s[i-2]!='.');
        }
    }
    cout<<min(dp[n-1][0],dp[n-1][1])<<'\n';
}