#include<bits/stdc++.h>
using namespace std;
int a[100];
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=2;i<=n;i++){
		if(abs(a[i]-a[i-1])!=7&&abs(a[i]-a[i-1])!=5){
			cout<<"No\n";
			return;
		}
	}
	cout<<"YES\n";
}
signed main(){
	int t=1;
	cin>>t;
	while(t--) solve();
}
