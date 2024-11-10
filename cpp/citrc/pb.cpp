#include<bits/stdc++.h>
#define int long long
using namespace std;
const int P=1e9+7;
int n,m;
int hd[200500],nxt[400500],to[400500];
int cnt=1;
int ans=0;
void addE(int a,int b){
	nxt[cnt]=hd[a];
	to[cnt]=b;
	hd[a]=cnt++;
}
int dfs(int x,int par){
	int ret=1;
	for(int e=hd[x];e;e=nxt[e]){
		if(to[e]==par) continue;
		int nw=dfs(to[e],x);
		ans=(ans+nw)%P;
		ret=(ret+nw*m)%P;
	}
	return ret;
}
signed main(){
	cin>>n>>m;
	int x,y;
	for(int i=0;i<n-1;i++){
		cin>>x>>y;
		addE(x,y);
		addE(y,x);
	}
	dfs(1,1);
	cout<<ans<<'\n';
}
