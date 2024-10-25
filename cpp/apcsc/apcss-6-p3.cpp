#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	vector<int> bask(m);
	for(auto& x:bask) cin>>x;
	vector<vector<int>> g(n);
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		for(int j=0;j<t;j++){
			int tmp;
			cin>>tmp;
			g[i].push_back(tmp-1);
		}
	}
	vector<int> apl(n);
	for(int i=0;i<n;i++){
		cin>>apl[i];
	}
	vector<int> ans(n,0);
	queue<pair<int,int>> q;
	vector<bool> vis(n,true);
	q.push({0,0});
	while(!q.empty()){
		auto tp=q.front();q.pop();
		vis[tp.first]=false;
		ans[tp.second]+=apl[tp.first];
		for(auto x:g[tp.first]){
			if(vis[x])
			q.push({x,tp.second+1});
		}
	}
	int times=0;
	for(int i=1;ans[i];i++){
		ans[i]+=ans[i-1];
		times=i;
	}
	for(auto x:bask){
		int opt=0;
		for(int j=times;j;j>>=1){
			while(opt+j<=times&&ans[opt+j]<=x)
				opt+=j;
		}
		cout<<opt<<'\n';
	}
	return 0;
}
