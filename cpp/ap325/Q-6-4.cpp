#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define chungAC ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MI 1<<30
bool cmp(pair<ll,ll> a,pair<ll,ll> b){
    return a.first*b.second<b.first*a.second;
}
signed main(){
    chungAC
    int n,t;
    cin>>n>>t;
    vector<vector<ll>> dp(n,vector<ll>(2,0));
    vector<vector<ll>> inp(n,vector<ll>(2));
    for(int i=0;i<n;i++){
        cin>>inp[i][0]>>inp[i][1];
    }
    dp[0][0]=abs(t-inp[0][0]);
    dp[0][1]=abs(t-inp[0][1]);
    for(int i=1;i<n;i++){
        dp[i][0]=min(abs(inp[i][0]-inp[i-1][0])+dp[i-1][0],abs(inp[i][0]-inp[i-1][1])+dp[i-1][1]);
        dp[i][1]=min(abs(inp[i][1]-inp[i-1][0])+dp[i-1][0],abs(inp[i][1]-inp[i-1][1])+dp[i-1][1]);
    }
    cout<<min(dp[n-1][0],dp[n-1][1])<<endl;
    return 0;
}