#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
	int n;
	int t,ans=0;
	char c;
	cin>>n;
	map<char,int> mp;
	for(int i=0;i<n;i++) {
		cin>>c>>t;
		mp[c]+=t;
	}
	for(char i='A';i<='Z';i++){
		int ori=mp[i];
		mp[i]%=2;
		if(mp[i]==0&&ori>0) mp[i]=2;
		ans+=mp[i];
	}
	cout<<ans<<'\n';
}
signed main(){
	int t;
	cin>>t;
	while(t--) solve();
}
