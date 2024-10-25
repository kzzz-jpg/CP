#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[15000];
int w[5000],v[5000];
int n,m;
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>w[i]>>v[i];
	for(int i=1;i<=n;i++){
		for(int j=m;j>=w[i];j--){
			dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
		}
	}
	cout<<dp[m]<<'\n';
}
