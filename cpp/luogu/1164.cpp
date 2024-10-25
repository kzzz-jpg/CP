#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[200],dp[200][10050];
int t;
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(j>=a[i]) dp[i][j]=dp[i-1][j]+dp[i-1][j-a[i]];
			else dp[i][j]=dp[i-1][j];
		}
	}
	cout<<dp[n][m]<<'\n';
}
