#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> g(200500),lca(21,vector<int> (200500));
vector<int> pth(200500,0),in(200500),out(200500);
int cnt=0,n,q;
void dfs(int x,int par){
	in[x]=cnt++;
	lca[0][x]=par;
	for(auto u:g[x]){
		if(u!=par){
			dfs(u,x);
			pth[x]+=pth[u];
		}
	}
	out[x]=cnt++;
}
void init(){
	for(int i=1;i<=20;i++){
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
 
	for(int i=20;i>=0;i--){
		while(lca[i][a]&&!isFath(lca[i][a],b)) a=lca[i][a];
	}
	return lca[0][a];
}
int main(){
	cin>>n>>q;
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1,0);
	init();
//	for(int i=1;i<=n;i++) cout<<lca[0][i]<<' ';
//	cout<<'\n';
	for(int i=0;i<q;i++){
		int a,b;
		cin>>a>>b;
		pth[a]++;
		pth[b]++;
		int Lca=qLca(a,b);
	//	cout<<Lca<<'\n';
		(pth[Lca]--);
		(pth[lca[0][Lca]]--);
//		cout<<Lca<<' '<<lca[0][Lca]<<'\n';
	}
//	for(int i=1;i<=n;i++) cout<<pth[i]<<' ';
	cnt=0;
	dfs(1,0);
	for(int i=1;i<=n;i++) cout<<pth[i]<<' ';
	cout<<'\n';
	return 0;
//	cout<<qLca(6,1)<<'\n';
}
