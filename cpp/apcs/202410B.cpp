#include<bits/stdc++.h>
using namespace std;
int g[102][102];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int n,m,k,r,c,scr,ans,fc;
int main(){
	cin>>n>>m>>k>>r>>c;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>g[i][j];
	for(int i=0;i<=n+1;i++) g[i][0]=g[i][m+1]=-1;
	for(int i=0;i<=m+1;i++) g[0][i]=g[n+1][i]=-1;
	r++,c++;
	for(;;){
		if(g[r][c]==0) break;
		scr+=g[r][c];
		ans++;
		g[r][c]--;
		if(scr%k==0) fc=(fc+1)%4;
		int nr=r+dir[fc][0],nc=c+dir[fc][1];
		while(g[nr][nc]==-1){
			fc=(fc+1)%4;
			nr=r+dir[fc][0],nc=c+dir[fc][1];
		}
		r=nr,c=nc;
	}
	cout<<ans<<'\n';
}
