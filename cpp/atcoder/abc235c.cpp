#include<bits/stdc++.h>
using namespace std;
map<int,vector<int>> mp;
int n,q;
signed main(){
	cin>>n>>q;
	int t;
	for(int i=1;i<=n;i++){
		cin>>t;
		mp[t].push_back(i);
	}
	int x,k;
	while(q--){
		cin>>x>>k;
		if(mp[x].size()<k) cout<<-1<<'\n';
		else cout<<mp[x][k-1]<<'\n';
	}
}
