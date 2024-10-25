#include<bits/stdc++.h>
using namespace std;
int x,y,a,b,c,d;
int dir[8][2]={{1,2},{2,1},{-1,2},{-2,-1},{1,-2},{-1,2},{2,-1},{-2,1}};
bool inR(int xx,int yy){
	return xx>=0&&xx<x&&yy>=0&&yy<y;
}
void solve(){
	cin>>x>>y>>a>>b>>c>>d;
	vector<vector<int>> g(x,vector<int>(y,0));
	queue<pair<int,int>> q;
	q.push({a,b});
	g[a][b]=1;
	while(q.size()){
		auto tp=q.front();q.pop();
		for(int i=0;i<8;i++){
			int nx=tp.first+dir[i][0],ny=tp.second+dir[i][1];
			if(inR(nx,ny)&&!g[nx][ny]){
				g[nx][ny]=g[tp.first][tp.second]+1;
				q.push({nx,ny});
			}
		}
	}
	cout<<g[c][d]-1<<'\n';
}
signed main(){
	int t=1;
	cin>>t;
	while(t--) solve();
}
