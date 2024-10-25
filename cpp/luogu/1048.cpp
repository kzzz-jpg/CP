#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int dp[200][2000];
int w[200],v[200];
signed main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>w[i]>>v[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(j<w[i]) dp[i][j]=dp[i-1][j];
			else dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
		}
	}
	cout<<dp[m][n]<<'\n';
}
