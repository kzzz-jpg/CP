#include<bits/stdc++.h>
#define int long long
using namespace std;
void test(int x){
	cout<<"----------------"<<x<<"---------------\n";
	for(int i=1;i<=100000;i++) if(x!=i&&(x%(x^i)==0||i%(x^i)==0)) {
		cout<<i<<' ';
		if(i>=2*x){
			cout<<"==============yes================";
			exit(0);
		}
	}
	cout<<'\n';
}
void solve(){
	int x,m;
	cin>>x>>m;
	int ans=0;
	for(int i=1;i<=min(m,4*x);i++){
		if(i!=x&&(x%(x^i)==0||i%(x^i)==0)) ans++;
	}
	cout<<ans<<'\n';
}
signed main(){
	int t;
	cin>>t;
	while(t--) solve();
}
