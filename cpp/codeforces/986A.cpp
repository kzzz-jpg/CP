#include<bits/stdc++.h>
using namespace std;
map<char,array<int,2>> mp;
void solve(){
	int n,a,b;
	cin>>n>>a>>b;
	string s;
	cin>>s;
	int x=0,y=0;
	bool flag=0;
	for(int i=0;i<500;i++){
		for(auto all:s){
			x+=mp[all][0],y+=mp[all][1];
			if(x==a&&y==b)flag=1;
		}
	}
	if(flag) cout<<"Yes\n";
	else cout<<"No\n";
}
signed main(){
	mp['N']={0,1};
	mp['E']={1,0};
	mp['S']={0,-1};
	mp['W']={-1,0};
	int t=1;
	cin>>t;
	while(t--) solve();
}
