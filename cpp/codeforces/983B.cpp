#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n,k;
	cin>>n>>k;
	int l=k-1,r=n-k;
	int mx=max(l,r),mn=min(l,r);
	if(n==1) {
		cout<<1<<'\n'<<1<<'\n';
		return;
	}
	if((mx-mn)&1||mn==0){
		cout<<-1<<'\n';
		return;
	}
	cout<<mn*2+1<<'\n';
	for(int i=1;i<=mn;i++) cout<<i<<' ';
	cout<<k<<' ';
	for(int i=k+1;i<=mn+k;i++) cout<<i<<' ';
	cout<<'\n';
}
signed main(){
	int t;
	cin>>t;
	while(t--) solve();
}
