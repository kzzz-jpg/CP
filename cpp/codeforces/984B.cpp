#include<bits/stdc++.h>
using namespace std;
int n,x,y,k;
void solve(){
	cin>>n>>k;
	vector<int> cs(k+1);
	for(int i=1;i<=k;i++){
		cin>>x>>y;
		cs[x]+=y;
	}

	sort(cs.begin()+1,cs.end(),greater<int>());
	int ans=0;
	for(int i=1;i<=min(k,n);i++) ans+=cs[i];
	cout<<ans<<'\n';
}
signed main(){
	int t=1;
	cin>>t;
	while(t--) solve();
}
