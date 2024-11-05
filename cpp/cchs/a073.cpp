#include<bits/stdc++.h>
using namespace std;
string s;
int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
signed main(){
	while(getline(cin,s)){
		int stx,sty,edx,edy;
		vector<string> g;
		g.push_back(s);
		while(1){
			getline(cin,s);
			if(s=="***") break;
			g.push_back(s);
		}
		int mxsz=0;
		for(auto x:g){
			mxsz=max(mxsz,(int)x.size());
		}
		for(auto x:g){
			while(x.size()<mxsz) x.push_back('w');
		}
		for(int i=0;i<g.size();i++){
			for(int j=0;j<mxsz;j++){
				if(g[i][j]=='s'){
					stx=i,sty=j;
				}
				if(g[i][j]=='e') edx=i,edy=j;
			}
		}
		vector<vector<int>> dis(g.size(),vector<int>(mxsz));
		queue<pair<int,int>> q;
		q.push({stx,sty});
		while(q.size()){
			auto tp=q.front();q.pop();
			for(int i=0;i<4;i++){
				int nx=tp.first+dir[i][0];
				int ny=tp.second+dir[i][1];
				if(nx>=0&&nx<g.size()&&ny>0&&ny<mxsz&&g[nx][ny]!='w'&&g[nx][ny]!='s'&&dis[nx][ny]==0){
					dis[nx][ny]=dis[tp.first][tp.second]+1;
					q.push({nx,ny});
				}
			}
		}
		cout<<dis[edx][edy]<<'\n';
	}
}
