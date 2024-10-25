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
    int n;
    cin>>n;
    vector<ll> inp(n);
    vector<ll> dp(n);
    for(int i=0;i<n;i++){
        cin>>inp[i];
    }
    dp[0]=inp[0];
    dp[1]=inp[1];
    dp[2]=min(dp[0],dp[1])+inp[2];
    for(int i=3;i<n;i++){
        dp[i]=min({dp[i-1],dp[i-2],dp[i-3]})+inp[i];
    }
    cout<<min(dp[n-1],dp[n-2])<<endl;
    return 0;
}