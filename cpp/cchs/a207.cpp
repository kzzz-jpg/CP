#include<bits/stdc++.h>
using namespace std;
int g[12][12],dis[12][12],vs[12][12];
pair<int,int> fa[12][12];
inline bool inR(int x,int y){
	return x>=1&&x<=10&&y>=1&&y<=10;
}
struct nd{
	int x,y,d,fax,fay;
	nd(int X,int Y,int D,int fx,int fy):x(X),y(Y),d(D),fax(fx),fay(fy){}
	bool operator <(nd o) const{
		return d>o.d;
	}
};
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
signed main(){
	for(int i=1;i<=10;i++) for(int j=1;j<=10;j++) cin>>g[i][j];
	priority_queue<nd> pq;
	pq.push(nd(1,1,g[1][1],-1,-1));
	while(pq.size()){
		auto tp=pq.top();pq.pop();
		if(vs[tp.x][tp.y]) continue;
		fa[tp.x][tp.y]={tp.fax,tp.fay};
		vs[tp.x][tp.y]=1;
		dis[tp.x][tp.y]=tp.d;
		for(int i=0;i<4;i++){
			int nx=tp.x+dir[i][0],ny=tp.y+dir[i][1];
			if(inR(nx,ny)&&!vs[nx][ny]) pq.push(nd(nx,ny,tp.d+g[nx][ny],tp.x,tp.y));
		}
	}
	cout<<dis[10][10];
	vector<pair<int,int>> ans;
	int nx=10,ny=10;
	while(!(nx==-1&&ny==-1)){
		ans.push_back({nx,ny});
		auto nw=fa[nx][ny];
		nx=nw.first,ny=nw.second;
	}
	reverse(ans.begin(),ans.end());
	for(auto x:ans) cout<<",["<<x.first-1<<','<<x.second-1<<']';
}
