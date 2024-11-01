#include<bits/stdc++.h>
using namespace std;
#define int long long
int hd[10050],nxt[200500],to[200500],pt[10050];
int n,m;
int cnt=1;
void addE(int a,int b){
	nxt[cnt]=hd[a];
	to[cnt]=b;
	hd[a]=cnt++;
}
int bhd[10050],bnxt[200500],bto[200500];
int deg[10050],mx[10050];
int ans=0;
void addEbh(int a,int b){
	bnxt[cnt]=bhd[a];
	bto[cnt]=b;
	bhd[a]=cnt++;
}
stack<int> s;
int low[10050],lev[10050];
bool instk[10050];
int bh[10050];
int bhpt[10050];
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
		bhpt[bhcnt]+=pt[x];
		instk[x]=0;
		while(s.top()!=x){
			bh[s.top()]=bhcnt;
			bhpt[bhcnt]+=pt[s.top()];
			instk[s.top()]=0;
			s.pop();
		}
		s.pop();
	}
}
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>pt[i];
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
	queue<int> q;
	for(int i=1;i<=bhcnt;i++) if(deg[i]==0) q.push(i);
	while(!q.empty()){
		auto tp=q.front();q.pop();
		ans=max(ans,mx[tp]+bhpt[tp]);
		for(int e=bhd[tp];e;e=bnxt[e]){
			mx[bto[e]]=max(mx[bto[e]],bhpt[tp]+mx[tp]);
			if(--deg[bto[e]]==0) q.push(bto[e]);
		}
	}
	cout<<ans<<'\n';
}
