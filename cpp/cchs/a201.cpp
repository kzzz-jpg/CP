#include<bits/stdc++.h>
using namespace std;
struct nd{
	bool lr,ud,isw;
} g[201][201];
int n,m,q;
int ans=0;
signed main(){
	cin>>n>>m>>q;
	int ln,x,y,op;
	while(q--){
		cin>>x>>y>>op;
		if(op==0){
			g[x][y]={0,0,1};
			ln=1;
			for(int i=x-1;i>=0;i--){
				if(g[i][y].isw) break;
				if(i==0&&ln) ln=0,i=x-1;
				g[i][y].ud=ln;
			}
			ln=1;
			for(int i=x+1;i<n;i++){
				if(g[i][y].isw) break;
				if(i==n-1&&ln) ln=0,i=x+1;
				g[i][y].ud=ln;
			}
			ln=1;
			for(int i=y-1;i>=0;i--){
				if(g[x][i].isw) break;
				if(i==0&&ln) ln=0,i=y-1;
				g[x][i].lr=ln;
			}
			ln=1;
			for(int i=y+1;i<m;i++){
				if(g[x][i].isw) break;
				if(i==m-1&&ln) ln=0,i=y+1;
				g[x][i].lr=ln;
			}
		}else{
			g[x][y]={0,0,0};
			for(int i=x-1;i>=0;i--){
				if(g[i][y].isw) break;
				g[i][y].ud=0;
			}
			for(int i=x+1;i<n;i++){
				if(g[i][y].isw) break;
				g[i][y].ud=0;
			}
			for(int i=y-1;i>=0;i--){
				if(g[x][i].isw) break;
				g[x][i].lr=0;
			}
			for(int i=y+1;i<m;i++){
				if(g[x][i].isw) break;
				g[x][i].lr=0;
			}
		}
		int nw=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(g[i][j].lr||g[i][j].ud||g[i][j].isw) nw++;
			}
		}
		ans=max(ans,nw);
	}
	cout<<ans<<'\n';
	ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(g[i][j].lr||g[i][j].ud||g[i][j].isw) ans++;
		}
	}
	cout<<ans<<'\n';
}