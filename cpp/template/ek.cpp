#include<bits/stdc++.h>
using namespace std;
#define int long long
int hd[200500],nxt[200500],to[200500],w[200500];
bool vs[200500];
int pre[200500];
int dis[200500];
int flag[500][500];
int cnt=2;
int s,t;
int n,m,ans;
void addE(int a,int b,int v){
	nxt[cnt]=hd[a];
	to[cnt]=b;
	w[cnt]=v;
	hd[a]=cnt++;
	nxt[cnt]=hd[b];
	w[cnt]=0;
	to[cnt]=a;
	hd[b]=cnt++;
}
bool bfs(){
	for(int i=1;i<=n;i++) vs[i]=0;
	queue<int> q;
	q.push(s);
	vs[s]=1;
	dis[s]=114514415;
	while(q.size()){
		auto tp=q.front();q.pop();
		for(int e=hd[tp];e;e=nxt[e]){
			if(vs[to[e]]) continue;
			if(w[e]==0) continue;
			dis[to[e]]=min(dis[tp],w[e]);
			pre[to[e]]=e;
			vs[to[e]]=1;
			q.push(to[e]);
			if(to[e]==t) return 1;
		}
	}
	return 0;
}
void upd(){
	int x=t;
	while(x!=s){
		int e=pre[x];
		w[e]-=dis[t];
		w[e^1]+=dis[t];
		x=to[e^1];
	}
	ans+=dis[t];
}
signed main(){
	cin>>n>>m>>s>>t;
	int x,y,v;
	for(int i=0;i<m;i++){
		cin>>x>>y>>v;
		if(flag[x][y]){
			w[flag[x][y]-2]+=v;
		}else{
			addE(x,y,v);
			flag[x][y]=cnt;
		}
	}
	while(bfs()){
		upd();
	}
	cout<<ans<<'\n';
}
