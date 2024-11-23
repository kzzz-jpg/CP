#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin>>n;
	cout<<1<<' ';
	for(int i=2;i<=n;i++) cout<<2*i-1<<" \n"[i==n];
}
signed main(){
	int t;
	cin>>t;
	while(t--) solve();
}
