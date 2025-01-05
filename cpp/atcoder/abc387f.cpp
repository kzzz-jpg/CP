#include<bits/stdc++.h>
using namespace std;
#define int long long
int hd[100050],nxt[200500],to[200500],pt[100050];
const int P=998244353;
int n,m;
int cnt=1;
void addE(int a,int b){
	nxt[cnt]=hd[a];
	to[cnt]=b;
	hd[a]=cnt++;
}
int bhd[100050],bnxt[200500],bto[200500];
int deg[100050],mx[100050];
int dp[2050][2050];
int ans=1;
void addEbh(int a,int b){
	bnxt[cnt]=bhd[a];
	bto[cnt]=b;
	bhd[a]=cnt++;
}
stack<int> s;
int low[100050],lev[100050];
bool instk[100050];
int bh[100050];
int bhpt[100050];
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
	for(int i=1;i<=n;i++) cin>>pt[i],addE(i,pt[i]);
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
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) dp[i][j]=1;
	queue<int> q;
	for(int i=1;i<=bhcnt;i++) if(deg[i]==0) {
        q.push(i);
    }
	while(!q.empty()){
		auto tp=q.front();q.pop();
        for(int j=1;j<=m;j++){
            dp[tp][j]=(dp[tp][j]+dp[tp][j-1])%P;
        }
		for(int e=bhd[tp];e;e=bnxt[e]){
            for(int j=1;j<=m;j++){
                dp[bto[e]][j]=(dp[bto[e]][j]*dp[tp][j])%P;
            }
			if(--deg[bto[e]]==0) q.push(bto[e]);
		}
       // cerr<<tp<<' '<<dp[tp][m]<<'\n';
        if(bhd[tp]==0) {
            ans=(ans*dp[tp][m])%P;
        }
	}
	cout<<ans<<'\n';
}
