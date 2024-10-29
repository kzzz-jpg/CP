#include<bits/stdc++.h>
using namespace std;
int g[5][5]={{-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1}};
int vs[5][5];
int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
int dd,ans=999;
bool chk(){
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++){
			if(g[i][j]==0) return 0;
		}
	return 1;
}
void dfs(int x,int y,int stp){
	if(stp>dd) return;
	vs[x][y]=1;
	g[x][y]^=1;
	for(int i=0;i<4;i++){
		int nx=x+dir[i][0];
		int ny=y+dir[i][1];
		if(g[nx][ny]==-1) continue;
		g[nx][ny]^=1;
	}
	if(chk()){
	       	ans=min(ans,stp);
		return;
	}
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++){
			if(vs[i][j]) continue;
			dfs(i,j,stp+1);
		}
	for(int i=0;i<4;i++){
		int nx=x+dir[i][0];
		int ny=y+dir[i][1];
		if(g[nx][ny]==-1) continue;
		g[nx][ny]^=1;
	}
	g[x][y]^=1;
	vs[x][y]=0;
}
signed main(){
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++) cin>>g[i][j];
	dd=3;
	for(dd=1;ans==999;dd++)	for(int i=1;i<=3;i++)for(int j=1;j<=3;j++) dfs(i,j,1);
	cout<<--dd<<'\n';
}

