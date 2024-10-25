#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,q,x,X,y,Y;
int g[1510][1510];
int pre[1510][1510];
signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>g[i][j];
			pre[i][j]=g[i][j];
		}
	}
	for(int i=1;i<=n;i++) pre[i][1]+=pre[i-1][1];
	for(int i=1;i<=m;i++) pre[1][i]+=pre[1][i-1];
	for(int i=2;i<=n;i++){
		for(int j=2;j<=m;j++){
			pre[i][j]+=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
		}
	}
	cin>>q;
	while(q--){
		cin>>x>>y>>X>>Y;
		x--,y--;
		int ans=pre[X][Y]-pre[X][y]-pre[x][Y]+pre[x][y];
		ans/=(X-x)*(Y-y);
		cout<<ans<<'\n';
	}
	return 0;
}
