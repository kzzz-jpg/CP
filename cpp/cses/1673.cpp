#include<bits/stdc++.h>
using namespace std;
#define int long long
int hd[3000],nxt[5050],to[5050],w[5050];
int n,m,cnt=1;;
void addE(int a,int b,int  v){
	nxt[cnt]=hd[a];
	to[cnt]=b;
	w[cnt]=v;
	hd[a]=cnt++;
}
int dis[3000],inqct[3000];
bool inq[3000];
bool vs[3000];
int ls[3000];
queue<int> q;
void spfa(int st){
	q.push(st);
	inq[st]=1;
	dis[st]=0;
	inqct[st]++;
	while(q.size()){
		auto tp=q.front();q.pop();
		vs[tp]=1;
		inq[tp]=0;
		for(int e=hd[tp];e;e=nxt[e]){
			if(dis[to[e]]>dis[tp]+w[e]){
				dis[to[e]]=dis[tp]+w[e];
				if(inqct[to[e]]<=n+10&&!inq[to[e]]){
					ls[to[e]]=tp;
					q.push(to[e]);
					inq[to[e]]=1;
					inqct[to[e]]++;
				}
			}
		}
	}
}
signed main(){
	cin>>n>>m;
	int x,y,v;
	for(int i=1;i<=n;i++) ls[i]=-1,dis[i]=1e15;
	for(int i=1;i<=m;i++) cin>>x>>y>>v,addE(x,y,v);
	for(int i=1;i<=n;i++){
		if(!vs[i]) spfa(i);
	}
	for(int i=1;i<=n;i++){
		if(inqct[i]>n){
			int nw=ls[i];
			cout<<"YES\n"<<i<<' ';
			while(nw!=i){
				cout<<nw<<' ';
				nw=ls[nw];
			}
			cout<<i<<'\n';
			return 0;
		}
	}
	cout<<"NO\n";
}
