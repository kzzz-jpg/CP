#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 9e8
int hd[505],nxt[20050],to[20050],w[20050];
int dis[505];
int cnt=2;
int n,m,s,t,ans;
int nw[505];
void addE(int a,int b,int v){
	nxt[cnt]=hd[a];
	to[cnt]=b;
	w[cnt]=v;
	hd[a]=cnt++;

	nxt[cnt]=hd[b];
	to[cnt]=a;
	w[cnt]=0;
	hd[b]=cnt++;
}	
bool bfs(){
	for(int i=1;i<=n;i++) dis[i]=inf;
	queue<int> q;
	q.push(s);
	dis[s]=1;
	nw[s]=hd[s];
	while(q.size()){
		auto tp=q.front();q.pop();
		for(int e=hd[tp];e;e=nxt[e]){
			if(w[e]==0) continue;
			if(dis[to[e]]!=inf) continue;
			dis[to[e]]=dis[tp]+1;
			nw[to[e]]=hd[to[e]];
			q.push(to[e]);
			if(to[e]==t) return 1;
		}
	}
	return 0;
}
int dfs(int x,int sum){
	if(x==t) return sum;
	int k,res=0;
	for(int e=nw[x];sum&&e;e=nxt[e]){
		nw[x]=e;
		if(w[e]==0) continue;
		if(dis[to[e]]-dis[x]!=1) continue;
		k=dfs(to[e],min(sum,w[e]));
		if(k==0) dis[to[e]]=inf;
		w[e]-=k;
		w[e^1]+=k;
		res+=k;
		sum-=k;
	}
	return res;
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	s=1,t=n;
	int x,y,v;
	for(int i=0;i<m;i++){
		cin>>x>>y>>v;
		addE(x,y,v);
	}
	while(bfs()){
		ans+=dfs(s,inf);
	}
	cout<<ans<<'\n';
}
				
