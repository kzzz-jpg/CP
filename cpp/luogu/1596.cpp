#include<bits/stdc++.h>
using namespace std;
char g[102][102];
int dir[8][2]={{1,1},{1,-1},{-1,1},{-1,-1},{0,1},{1,0},{-1,0},{0,-1}};
int n,m,ans;
void dfs(int x,int y){
	g[x][y]='.';
	for(int i=0;i<8;i++){
		int nx=x+dir[i][0],ny=y+dir[i][1];
		if(g[nx][ny]=='W') dfs(nx,ny);
	}
}
signed main(){
	cin>>n>>m;
	for(int i=0;i<=n+1;i++){
		for(int j=0;j<=m+1;j++){
			g[i][j]='.';
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) cin>>g[i][j];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(g[i][j]=='W'){
				ans++;
				dfs(i,j);
			}
		}
	}
	cout<<ans<<'\n';
}
