#include<bits/stdc++.h>
using namespace std;
int dir[8][2]={{1,2},{2,1},{1,-2},{-2,1},{-1,2},{2,-1},{-1,-2},{-2,-1}};
int goal[6][6]={
	{0,0,0,0,0,0},
	{0,1,1,1,1,1},
	{0,0,1,1,1,1},
	{0,0,0,2,1,1},
	{0,0,0,0,0,1},
	{0,0,0,0,0,0}
};
int g[6][6];
int s,t,ans,dd;
inline bool inR(int x,int y){return x>=1&&x<=5&&y>=1&&y<=5;}
int ev(){
	int ret=0;
	for(int i=1;i<=5;i++)
		for(int j=1;j<=5;j++)
			if(g[i][j]!=goal[i][j]) ret++;
	return ret;
}
void dfs(int x,int y,int ls,int ly,int stp){
	int e=ev();
	if(e==0){
		ans=min(ans,stp);
		return;
	}
	if(stp+e>dd+2) return;
	for(int i=0;i<8;i++){
		int nx=dir[i][0]+x,ny=dir[i][1]+y;
		if(nx==ls&&ny==ly) continue;
		if(!inR(nx,ny)) continue;
		swap(g[x][y],g[nx][ny]);
		dfs(nx,ny,x,y,stp+1);
		swap(g[x][y],g[nx][ny]);
	}
}
void solve(){
	ans=999;
	char c;
	for(int i=1;i<=5;i++)
		for(int j=1;j<=5;j++){
			cin>>c;
			if(c=='*')
				g[i][j]=2,s=i,t=j;
			else g[i][j]=c-'0';
		}
	for(dd=ev();ans==999&&dd<=15;dfs(s,t,0,0,1),dd++);
	if(ans==999) cout<<-1<<'\n';
	else
	cout<<ans-1<<'\n';
}
signed main(){
	int t;
	cin>>t;
	while(t--) solve();
}
