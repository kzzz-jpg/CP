#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>> g(100500);
signed main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(auto 
