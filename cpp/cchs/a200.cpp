#include<bits/stdc++.h>
using namespace std;
void solve(){
	char c;
	int sum=0;
	for(int i=0;i<12;i++) {
		cin>>c;
		if(!(i&1)) sum+=c-'0';
		else sum+=(c-'0')*3;
	}
	cout<<(10-sum%10)%10<<'\n';
}
signed main(){
	int t=1;
	cin>>t;
	while(t--) solve();
}
