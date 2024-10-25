#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[1050][1050];
int w[1050],ls[1050],c[1050];
int n,m;
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ls[i]>>w[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(j<c[i]) dp[i][j]=dp[i-1][j]+ls[i];
			else dp[i][j]=max(dp[i-1][j]+ls[i],dp[i-1][j-c[i]]+w[i]);
		}
	}
	cout<<dp[n][m]*5<<'\n';
}
