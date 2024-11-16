#include<bits/stdc++.h>
using namespace std;
char g[102][102];
bool vs[102][102];
int ans=0;
int n,m;
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) cin>>g[i][j];
	}
	for(int i=0;i<=m;i++) g[0][i]=g[n+1][i]='#';
	for(int  i=0;i<=n;i++) g[i][0]=g[i][m+1]='#';
	queue<pair<int,int>> q;
	q.push({1,1});
	vs[1][1]=1;
	while(q.size()){
		auto tp=q.front();q.pop();
		int x=tp.first,y=tp.second;
		int nx=tp.first+1,ny=tp.second+1;
		if(g[nx][y]!='#'&&!vs[nx][y]){
			q.push({nx,y});
			vs[nx][y]=1;
		}
		if(g[x][ny]!='#'&&!vs[x][ny]){
			q.push({x,ny});
			vs[x][ny]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(vs[i][j]){
				ans=max(ans,i-1+j-1+1);
			}
		}
	}
	cout<<ans<<'\n';
}
