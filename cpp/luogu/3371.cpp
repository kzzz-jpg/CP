#include<bits/stdc++.h>
using namespace std;
#define int long long
int hd[200500],nxt[200500],to[200500],w[200500];
bool vs[200500];
int dis[200500];
void addE(int a,int b,int v){
	nxt[cnt]=hd[a];
	to[cnt]=b;
	w[cnt]=v;
	hd[a]=cnt++;
}
void dig(int st){
	priority_queue<pair<int,int>> pq;
	pq.push({0,st});
	vs[st]=1;
	while(pq.size()){
		auto tp=pq.top();pq.pop();
		if(vs[tp.second]) continue;
		dis[to.second]=tp.first;
		for(int e=hd[tp.second];e;e=nxt[e]){
			if(!vs[to[e]]){
				vs[to[e]]=1;
				pq.push({tp.first+w[e],to[e]});
			}
		}
	}
}
