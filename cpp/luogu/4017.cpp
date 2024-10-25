#include<bits/stdc++.h>
using namespace std;
#define int long long
int deg[5050];
int ot[5050];
int hd[5050],nxt[500500],to[500500];
int ans[5050];
int cnt=1;
void addE(int a,int b){
	nxt[cnt]=hd[a];
	to[cnt]=b;
	hd[a]=cnt++;
}
int n,m,u,v,mx;
signed main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>u>>v;
		addE(u,v);
		deg[v]++;
		ot[u]++;
	}
	queue<int> q;
	for(int i=1;i<=n;i++) 
		if(deg[i]==0) q.push(i),ans[i]=1;

	while(!q.empty()){
		auto tp=q.front();q.pop();
		for(int e=hd[tp];e;e=nxt[e]){
			ans[to[e]]=(ans[to[e]]+ans[tp])%80112002;
			//cout<<to[e]<<'\n';
			if(--deg[to[e]]==0) q.push(to[e]);
		}
	}
	for(int i=1;i<=n;i++) if(ot[i]==0) mx=(mx+ans[i])%80112002;
	cout<<mx%80112002<<'\n';
}
