#include<bits/stdc++.h>
using namespace std;
#define int long long
int g[15][15];
int n,m;
signed main(){
	for(int i=0;i<15;i++) for(int j=0;j<15;j++) g[i][j]=1e15;
	int x,y,v;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>x>>y>>v;
		x--,y--;
		g[x][y]=g[y][x]=min(g[x][y],v);
	}
	for(int i=0;i<n;i++) dp[i][1<<i]=0;
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<n;j++){
			if(!(i&(1<<j))) continue;
			for(int k=0;k<n;k++){
				if(i&(1<<k)){
					dp[j][i]=min(dp[j][i],dp[j][i&(~(1<<j))]+g[j][k]);
