#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[300];
int a[300];
signed main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dp[1]=0;
	for(int i=2;i<=n;i++){
		dp[i]=1e15;
		if(dp[i-1]==-1) dp[i]=-1;
		else if(a[i]-a[i-1]<=1) dp[i]=dp[i-1]+1;
		else{
			for(int j=i-1;j>=1;j--){
				for(int k=1;j-k>=1;k++){
					if(a[i]-a[j-k]<=(1<<k)){
						dp[i]=min(dp[i],dp[j]+k+1);
					}
				}
			}
			if(dp[i]==1e15) dp[i]=-1;
		}
	}
	cout<<dp[n]<<'\n';
}
