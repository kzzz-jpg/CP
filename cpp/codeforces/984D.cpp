#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n,m,ans=0;
	cin>>n>>m;
	vector<vector<int>> g(n,vector<int>(m));
	char c;
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>c,g[i][j]=c-'0';
	vector<vector<int>> v;
	for(int i=0;i<(n>>1);i++){
		v.push_back(vector<int>());
		for(int j=i;j<m-i;j++) {
			v[i].push_back(g[i][j]);
		}
		for(int j=i+1;j<n-i-1;j++) {
			v[i].push_back(g[j][m-i-1]);
		}
		for(int j=m-i-1;j>=i;j--) {
			v[i].push_back(g[n-i-1][j]);
		}
		for(int j=n-i-2;j>=i+1;j--) {
			v[i].push_back(g[j][i]);
		}
	}
	for(auto x:v){
		for(int i=0;i<x.size();i++){
			if(x[i]==1&&x[(i+1)%x.size()]==5&&x[(i+2)%x.size()]==4&&x[(i+3)%x.size()]==3) ans++;
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	int t=1;
	cin>>t;
	while(t--) solve();
}
