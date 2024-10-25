#include<bits/stdc++.h>
using namespace std;
int hd[200500],nxt[400500],to[400500];
int cnt=1;
void addE(int a,int b){
	nxt[cnt]=hd[a];
	to[cnt]=b;
	hd[a]=cnt++;
}
int n,m,x,y;
int vs[200500];
signed main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>x>>y;
		addE(x,y);
	}
	queue<int> q;
	q.push(1);
	while(q.size()){
		auto tp=q.front();q.pop();
		for(int e=hd[tp];e;e=nxt[e]){
			if(vs[to[e]]) continue;
			vs[to[e]]=vs[tp]+1;
			q.push(to[e]);
		}
	}
	if(vs[1]==0) cout<<-1<<'\n';
	else cout<<vs[1]<<'\n';
}
