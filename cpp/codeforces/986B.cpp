#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,a,b;
	cin>>n>>a>>b;
	if(a==0){
		if(b<n-2) cout<<(-1)<<'\n';
		else if(b==n-1||b==n-2) cout<<(n-1)<<'\n';
		else cout<<n<<'\n';
		return;
	}
	int nw=(n-1-b)/a;
	if(n-1-b<0) cout<<n<<'\n';
	else{
		cout<<(n-1-nw)<<'\n';
	}
}
signed main(){
	int t=1;
	cin>>t;
	while(t--) solve();
}
