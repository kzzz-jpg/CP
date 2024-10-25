#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int dp[10005000];
int w[10500],v[10500];
signed main(){
	cin>>m>>n;
	for(int i=1;i<=n;i++) cin>>w[i]>>v[i];
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(j>=w[i])
			dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
		}
	}
	cout<<dp[m]<<'\n';
}
