#include<bits/stdc++.h>
using namespace std;
#define get(x,j) ((x>>j)&1)
#define set(s,j,x) ((x==1)?(s|(1<<j)):(s&(~(1<<j))))
const int P=1e8;
int n,m;
int g[12][12];
int dp[13][1<<12];
int last[1<<12];
/*int f(int i,int j,int s){
	if(i==n) return 1;
	if(j==m){
		return f(i+1,0,s);
	}
	if(dp[i][j][s]!=-1) return dp[i][j][s];
	int ans=f(i,j+1,set(s,j,0));
	if(g[i][j]==1&&(j==0||get(s,j-1)==0)&&get(s,j)==0) ans=(ans+f(i,j+1,set(s,j,1)))%P;
	dp[i][j][s]=ans;
	return ans;
}
void init(){
	for(int i=0;i<12;i++) for(int j=0;j<12;j++) for(int s=0;s<(1<<12);s++) dp[i][j][s]=-1;
}*/
void solve(){
	for(int i=0;i<(1<<m);i++) last[i]=1;
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<(1<<m);j++) dp[m][j]=last[j];

		for(int j=m-1;j>=0;j--){
			for(int s=0;s<(1<<m);s++){
				dp[j][s]=dp[j+1][set(s,j,0)];
				if(g[i][j]==1&&(j==0||get(s,j-1)==0)&&get(s,j)==0) 
					dp[j][s]=(dp[j][s]+dp[j+1][set(s,j,1)])%P;
			}
		}

		for(int j=0;j<(1<<m);j++) last[j]=dp[0][j];
	}
	cout<<dp[0][0]<<'\n';
}
signed main(){
	cin>>n>>m;
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>g[i][j];
	solve();
}
