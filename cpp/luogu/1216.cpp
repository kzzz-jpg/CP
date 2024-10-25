#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1010][1010];
int dp[1010][1010];
int n;
int dfs(int l,int r){
	if(l==n) return a[n][r];
	if(dp[l][r]!=-1) return dp[l][r];
	int ans=max(dfs(l+1,r),dfs(l+1,r+1))+a[l][r];
	dp[l][r]=ans;
	//out<<ans<<'\n';
	return ans;
}
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin>>a[i][j];
			dp[i][j]=-1;
		}
	}
	cout<<dfs(1,1)<<'\n';
}
