#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
int dp[500][1000];
int rg[500];
void solve(){
	cin>>n>>k;
	for(int i=1,r=1;i<2*n-1;i+=2,r+=2){
		rg[i]=rg[i+1]=r;
	}
	rg[2*n-1]=n*2-1;
	dp[0][0]=1;
	for(int i=1;i<2*n;i++){
		dp[i][0]=dp[i-1][0];
		for(int j=1;j<=k;j++){
			dp[i][j]=(dp[i-1][j-1]*max((int)0,(rg[i]-j+1))+dp[i-1][j])%504;
		}
	}
	cout<<dp[2*n-1][k]%504<<'\n';
}
signed main(){
	int t=1;
	while(t--){
		solve();
	}
}
