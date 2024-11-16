#include<bits/stdc++.h>
using namespace std;
int g[10][10];
int rg[10][10];
int rel[10];
int n,m;
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) rel[i]=i;
	int x,y;
	for(int i=0;i<m;i++) cin>>x>>y,g[x][y]=1,g[y][x]=1;
	for(int i=0;i<m;i++) cin>>x>>y,rg[x][y]=1,rg[y][x]=1;
	do{
		bool flag=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(g[i][j]!=rg[rel[i]][rel[j]]) flag=0;
			}
		}
		if(flag){
			cout<<"Yes\n";
			return 0;
		}
	}while(next_permutation(rel+1,rel+1+n));
	cout<<"No\n";
}
