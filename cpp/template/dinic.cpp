#include<bits/stdc++.h>
using namespace std;
#define int long long
int hd[200500],nxt[200500],to[200500],w[200500];
int dis[200500];
int cnt=2;
int n,m,s,t,ans;
int nw[200500];
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
	for(int i=1;i<=n;i++) dis[i]=99999;
	queue<int> q;
	q.push(s);
	dis[s]=1;
	nw[s]=hd[s];
	while(q.size()){
		auto tp=q.front();q.pop();
		for(int e=hd[tp];e;e=nxt[e]){
			if(w[e]==0) continue;
			if(dis[to[e]]!=99999) continue;
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
		if(k==0) dis[to[e]]=99999;
		w[e]-=k;
		w[e^1]+=k;
		res+=k;
		sum-=k;
	}
	return res;
}
signed main(){
	cin>>n>>m>>s>>t;
	int x,y,v;
	for(int i=0;i<m;i++){
		cin>>x>>y>>v;
		addE(x,y,v);
	}
	while(bfs()){
		ans+=dfs(s,999999);
	}
	cout<<ans<<'\n';
}
				
