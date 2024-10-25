#include<bits/stdc++.h>
using namespace std;
#define int long long
const int P=1e6+7;
int n,m;
int a[150];
int dp[150][150];
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			for(int k=0;k<=min(j,a[i]);k++) dp[i][j]=(dp[i][j]+dp[i-1][j-k])%P;
		}
	}
	cout<<dp[n][m]<<'\n';
}
