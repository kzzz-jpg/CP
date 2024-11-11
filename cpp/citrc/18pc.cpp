#include<bits/stdc++.h>
using namespace std;
map<char,array<int,2>> mp;
void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	int x=0,y=0;
	for(auto all:s) x+=mp[all][0],y+=mp[all][1];
	cerr<<x<<' '<<y<<'\n';
	if((x%2!=0)||(y%2!=0)){
		cout<<"NO\n";
		return;
	}
	y/=2;
	x/=2;
	int nx=0,ny=0;
	for(int i=0;i<s.size();i++){
		nx+=mp[s[i]][0],ny+=mp[s[i]][1];
		if(nx<=x&&ny<=y){
			cout<<'R';
		}else{
			cout<<'H';
			nx-=mp[s[i]][0],ny-=mp[s[i]][1];
		}
	}
	cout<<'\n';
}
signed main(){
	mp['N']={0,1};
	mp['S']={0,-1};
	mp['E']={1,0};
	mp['W']={-1,0};
	int t=1;
	cin>>t;
	while(t--) solve();
}
