#include<bits/stdc++.h>
using namespace std;
int a[1050][1050],dp[1050][1050];
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int n,m;
int mx;
bool inR(int x,int y){
	return x>0&&x<=n&&y>0&&y<=m;
}
int dfs(int x,int y){
	if(dp[x][y]) return dp[x][y];
	int ans=0;
	for(int i=0;i<4;i++){
		int nx=x+dir[i][0],ny=y+dir[i][1];
		if(inR(nx,ny)&&a[x][y]>a[nx][ny]){
			ans=max(ans,dfs(nx,ny));
		}
	}
	return dp[x][y]=ans+1;
}
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) cin>>a[i][j];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) mx=max(mx,dfs(i,j));
	}
	cout<<mx<<'\n';
}
