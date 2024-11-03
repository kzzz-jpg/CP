#include<bits/stdc++.h>
using namespace std;
void solve(){
	int x,y,k;
	cin>>x>>y>>k;
	int mn=min(x,y);
	x=mn,y=mn;
	cout<<0<<' '<<0<<' '<<x<<' '<<y<<'\n';
	cout<<0<<' '<<y<<' '<<x<<' '<<0<<'\n';
}
signed main(){
	int t;
	cin>>t;
	while(t--) solve();
}
