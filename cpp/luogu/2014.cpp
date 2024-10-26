#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int hd[350],nxt[350],to[350];
int dp[350][350];
int cnt=1;
void addE(int a,int b){
	nxt[cnt]=hd[a];
	to[cnt]=b;
	hd[a]=cnt++;
}
void dfs(int a){
	for(int e=hd[a];e;e=nxt[e]){
		dfs(to[e]);
	}
	for(int e=hd[a];e;e=nxt[e]){
		for(int j=m;j>0;j--){
			for(int k=0;k<j;k++){
				dp[a][j]=max(dp[a][j],dp[a][j-k]+dp[to[e]][k]);
			}
		}
	}
}
signed main(){
	cin>>n>>m;
	m++;
	int pa;
	for(int i=1;i<=n;i++){
		cin>>pa>>dp[i][1];
		addE(pa,i);
	}
	dfs(0);
	cout<<dp[0][m]<<'\n';
}
