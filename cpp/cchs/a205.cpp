#include<bits/stdc++.h>
using namespace std;
int h[1050];
int vs[1050],dp[1050];
int hd[1050],nxt[200500],to[200500],w[200500];
int cnt;
void addE(int a,int b,int c){
	nxt[cnt]=hd[a];
	to[cnt]=b;
	w[cnt]=c;
	hd[a]=cnt++;
}
void dij(){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push({0,2});
	while(!pq.empty()){
		auto tp=pq.top();pq.pop();
		if(vs[tp.second]) continue;
		vs[tp.second]=1;
		h[tp.second]=tp.first;
		for(int e=hd[tp.second];e;e=nxt[e]){
			if(!vs[to[e]]){
				pq.push({h[tp.second]+w[e],to[e]});
			}
		}
	}
}
int n,m;
signed main(){
	while(cin>>n){
		if(n==0) break;
		cin>>m;
		for(int i=0;i<=1000;i++){
			dp[i]=hd[i]=h[i]=vs[i]=0;
			cnt=1;
		}
		int x,y,v;
		for(int i=0;i<m;i++){
			cin>>x>>y>>v;
			addE(x,y,v);
			addE(y,x,v);
		}
		dij();
		priority_queue<pair<int,int>> pq;
		pq.push({h[1],1});
		dp[1]=1;
		while(pq.size()){
			auto tp=pq.top();pq.pop();
			for(int e=hd[tp.second];e;e=nxt[e]){
				if(h[to[e]]<h[tp.second]){
					if(!dp[to[e]]) pq.push({h[to[e]],to[e]});
					dp[to[e]]+=dp[tp.second];
				}
			}
		}
		cout<<dp[2]<<'\n';
	}
}
