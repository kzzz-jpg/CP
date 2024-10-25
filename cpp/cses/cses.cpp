#include<bits/stdc++.h>
int n,q,cnt=0,cnt2=0;
using namespace std;
vector<vector<int>> g(200500),lca(20,vector<int>(200500));
vector<int> in(200500),out(200500);
void dfs(int x,int par){
	in[x]=cnt++;
	lca[0][x]=par;
	for(auto u:g[x]){
		if(u!=par){
			dfs(u,x);
		}
	}
	out[x]=cnt2++;
}
void init(){
	for(int i=1;i<20;i++){
		for(int a=1;a<=n;a++){
			lca[i][a]=lca[i-1][lca[i-1][a]];
		}
	}
}
bool isFath(int a,int b){
	if(in[a]<=in[b]&&out[a]>=out[b]) return true;
	else return false;
}
int qLca(int a,int b){
    if(isFath(a,b)) return a;
	for(int i=19;i>=0;i--){
		if(!isFath(lca[i][a],b)) a=lca[i][a];
	}
	return lca[0][a];
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	for(int i=2;i<=n;i++){
		int a;
		cin>>a;
		g[a].push_back(i);
	}
	dfs(1,1);
	init();
	for(int i=0;i<q;i++){
		int l,r;
		cin>>l>>r;
		cout<<qLca(l,r)<<'\n';
	}
    return 0;
}