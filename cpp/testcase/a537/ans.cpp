#include<bits/stdc++.h>
using namespace std;
int n,m;
signed main(){
	cin>>n>>m;
	vector<vector<int>> g(n+1);
	int x,y;
	for(int i=0;i<m;i++){
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		if(g[i].size()){
			sort(g[i].begin(),g[i].end());
			for(auto xx:g[i]) cout<<xx<<' ';
			cout<<'\n';
		}else{
			cout<<0<<'\n';
		}
	}
}
