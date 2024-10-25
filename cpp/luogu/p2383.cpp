#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
	int n;
	cin>>n;
	map<int,int> mp;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		if(++mp[t]==4){
			cout<<"yes\n";
			return;
		}
	}
	cout<<"no\n";
}
signed main(){
	int t;
	cin>>t;
	while(t--) solve();
}
