#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[300],dp[300][300];
signed main(){
	int n;
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n/2+(n&1);j++){
			dp[i][j]=dp[i-1][j];
			if(dp[i-1][j-1]+a[i]<=sum/2) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+a[i]);
		}
	}
	int ans=max(dp[n][n/2],dp[n][n/2+(n&1)]);
	cout<<min(sum-ans,ans)<<' '<<max(ans,(sum-ans))<<'\n';
}
