#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define int long long
int hd[100500],nxt[200500],to[200500],wei[200500];
int cnt=1;
int dis[100500],n,m;
bool vs[100500];
void addE(int a,int b,int w){
	nxt[cnt]=hd[a];
	to[cnt]=b;
	wei[cnt]=w;
	hd[a]=cnt++;
}
struct nd{
	int v,w,n;
	nd(int V,int W,int N):v(V),w(W),n(N){}
	bool operator <(nd ano) const{
		return w<ano.w;
	}
};
int mn=1e15,mx,num;
const int P=1e9+7;
inline void dij(int s){
	priority_queue<nd> pq;
	pq.push(nd(s,0,0));
	while(pq.size()){
		auto tp=pq.top();pq.pop();
		if(!vs[tp.v]){
			vs[tp.v]=1;
			dis[tp.v]=tp.w;
			cout<<tp.v<<' '<<tp.w<<'\n';
		}else{
			if(tp.w!=dis[tp.v]) continue;
		}
		if(tp.v==n){
			num++;
			mn=min(mn,tp.n);
			mx=max(mx,tp.n);
			continue;
		}
		for(int e=hd[tp.v];e;e=nxt[e]){
			pq.push(nd(to[e],tp.w+wei[e],tp.n+1));
		}
	}
}
signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	int a,b,w;
	for(int i=0;i<m;i++){
		cin>>a>>b>>w;
		addE(a,b,w);
	}
	dij(1);
	cout<<dis[n]<<' '<<num%P<<' '<<mn<<' '<<mx<<'\n';
}
