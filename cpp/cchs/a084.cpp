#include<bits/stdc++.h>
using namespace std;
void solve(){
	char c;
	int sum=0;
	for(int i=0;i<11;i++) {
		cin>>c;
		if(i&1) sum+=c-'0';
		else sum+=(c-'0')*3;
	}
	for(int i=0;i<=9;i++){
		if((sum+i)%10==0){
			cout<<i<<'\n';
			return;
		}
	}
	cout<<-1<<'\n';
}
signed main(){
	int t=1;
	cin>>t;
	while(t--) solve();
}
