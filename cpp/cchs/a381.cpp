#include<bits/stdc++.h>
using namespace std;
int s,t;
char g[28][7];
int dir[3][2]={{1,0},{0,1},{0,-1}};
bool vs[28][7];
struct pr{
	int fx,fy;
} pre[28][7];
signed main(){
	for(int i=0;i<28;i++){
		for(int j=0;j<7;j++){
		       	cin>>g[i][j];
			if(g[i][j]=='S') s=i,t=j;
		}
	}
	queue<pr> q;
	q.push({s,t});
	while(q.size()){
		auto tp=q.front();q.pop();
		for(int i=0;i<3;i++){
			int nx=tp.fx+dir[i][0];
			int ny=tp.fy+dir[i][1];
			if(!vs[nx][ny]){
				q.push({nx,ny});
				pre[nx][ny]=
