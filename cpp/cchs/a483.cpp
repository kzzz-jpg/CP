#include<bits/stdc++.h>
using namespace std;
int g[1000][1000];
int n;
signed main(){
	cin>>n;
	int x,xx,y,yy;
	for(int i=0;i<n;i++){
		cin>>x>>y>>xx>>yy;
		x++,y++,xx++,yy++;
		g[xx][y]+=(1<<i);
		g[x+1][y]-=(1<<i);
		g[xx][yy+1]-=(1<<i);
		g[x+1][yy+1]+=(1<<i);
	}
	for(int i=1;i<1000;i++){
		for(int j=1;j<1000;j++){
			g[i][j]+=g[i][j-1];
		}
	}
	for(int i=1;i<1000;i++){
		for(int j=1;j<1000;j++){
			g[j][i]+=g[j-1][i];
		}
	}
	int ans=0;
	map<int,int> mp;
	for(int i=0;i<1000;i++){
		for(int j=0;j<1000;j++){
			if(g[i][j]==0) continue;
			if(mp[g[i][j]]++==0) ans++;
		}
	}
	cout<<ans<<'\n';
}
