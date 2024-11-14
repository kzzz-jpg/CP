#include<bits/stdc++.h>
using namespace std;
struct nd{
	int lr,ud;
	int isbk;
	int lig;
} g[1505][1505];
int h,w,n,m,ans;
signed main(){
	cin>>h>>w>>n>>m;
	int x,y;
	for(int i=0;i<n;i++) cin>>x>>y,g[x][y].lig=g[x][y].lr=g[x][y].ud=1,ans++;
	for(int i=0;i<m;i++) cin>>x>>y,g[x][y].isbk=1;
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			if(g[i][j].isbk) continue;
			if(g[i-1][j].ud){
				g[i][j].ud=1;
				if(g[i][j].lig++==0) ans++;
			}
			if(g[i][j-1].lr){
				g[i][j].lr=1;
				if(g[i][j].lig++==0) ans++;
			}
		}
	}
	for(int i=h;i>=1;i--){
		for(int j=w;j>=1;j--){
			if(g[i][j].isbk) continue;
			if(g[i+1][j].ud){
				g[i][j].ud=1;
				if(g[i][j].lig++==0) ans++;
			}
			if(g[i][j+1].lr){
				g[i][j].lr=1;
				if(g[i][j].lig++==0) ans++;
			}
		}
	}
	cout<<ans<<'\n';
}
