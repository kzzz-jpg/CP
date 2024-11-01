#include<bits/stdc++.h>
using namespace std;
#define int long long
int hd[100050],nxt[500500],to[500500];
int n,m;
int cnt=1;
void addE(int a,int b){
	nxt[cnt]=hd[a];
	to[cnt]=b;
	hd[a]=cnt++;
}
int bhd[100050],bnxt[500500],bto[500500];
int deg[100050];
int ans=0;
void addEbh(int a,int b){
	bnxt[cnt]=bhd[a];
	bto[cnt]=b;
	bhd[a]=cnt++;
}
stack<int> s;
int low[100050],lev[100050];
bool instk[100050];
int bh[100050];
int bhcnt;
int dfn=1;
void tarjan(int x){
	low[x]=lev[x]=dfn++;
	s.push(x);
	instk[x]=1;
	for(int e=hd[x];e;e=nxt[e]){
		if(!lev[to[e]]){
			tarjan(to[e]);
			low[x]=min(low[x],low[to[e]]);
		}else if(instk[to[e]]){
			low[x]=min(low[x],low[to[e]]);
		}
	}
	if(low[x]==lev[x]){
		bh[x]=++bhcnt;
		instk[x]=0;
		while(s.top()!=x){
			bh[s.top()]=bhcnt;
			instk[s.top()]=0;
			s.pop();
		}
		s.pop();
	}
}
signed main(){
	cin>>n>>m;
	int x,y;
	for(int i=0;i<m;i++) {
		cin>>x>>y;
		addE(x,y);
	}
	for(int i=1;i<=n;i++) if(!lev[i]) tarjan(i);
	cnt=1;
	for(int i=1;i<=n;i++){
		for(int e=hd[i];e;e=nxt[e]){
			if(bh[i]!=bh[to[e]]){
				addEbh(bh[i],bh[to[e]]);
				deg[bh[to[e]]]++;
			}
		}
	}
	for(int i=1;i<=bhcnt;i++) if(deg[i]==0) ans++;
	cout<<ans<<'\n';
}