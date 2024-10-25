#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,x,y;
int dp[50][50];
signed main(){
	cin>>x>>y>>n>>m;
	x++,y++,n++,m++;
	x++,y++,n++,m++;
	dp[n][m]=dp[n-1][m-2]=dp[n-2][m-1]=dp[n+1][m+2]=dp[n+2][m+1]=-1;
	dp[n-1][m+2]=dp[n-2][m+1]=dp[n+1][m-2]=dp[n+2][m-1]=-1;
	dp[2][2]=1;
	for(int i=2;i<=x;i++)
		for(int j=2;j<=y;j++)
			if(dp[i][j]!=-1){
				dp[i][j]+=max((int)0,dp[i-1][j])+max((int)0,dp[i][j-1]);
	//			cout<<dp[i][j]<<' ';
			}
	cout<<dp[x][y]<<'\n';
}
