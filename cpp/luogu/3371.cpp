#include<bits/stdc++.h>
using namespace std;
#define int long long
int hd[200500],nxt[500500],to[500500],w[500500];
bool vs[200500];
int dis[200500];
int n,m,s,cnt=1;
void addE(int a,int b,int v){
	nxt[cnt]=hd[a];
	to[cnt]=b;
	w[cnt]=v;
	hd[a]=cnt++;
}
void dig(int st){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push({0,st});
	while(pq.size()){
		auto tp=pq.top();pq.pop();
		if(vs[tp.second]) continue;
		vs[tp.second]=1;
		dis[tp.second]=tp.first;
		for(int e=hd[tp.second];e;e=nxt[e]){
			if(!vs[to[e]]){
				pq.push({tp.first+w[e],to[e]});
			}
		}
	}
}
signed main(){
	int x,y,v;
	cin>>n>>m>>s;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>v;
		addE(x,y,v);
	}
	dig(s);
	for(int i=1;i<=n;i++){
		if(!vs[i]) cout<<(1LL<<31)-1<<' ';
		else cout<<dis[i]<<' ';
	}
}
