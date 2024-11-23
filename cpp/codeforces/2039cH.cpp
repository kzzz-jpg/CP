#include<bits/stdc++.h>
#pragma GCC optimize(2)
#define int long long
using namespace std;
/*
int test(int x){
	int ans=0;
	for(int i=1;i<=1000;i++) if((x^i)%i==0||(x^i)%x==0) ans++;
	return ans;
}*/
int lcm(int x){
	int gg=(1LL<<(x-1==0?0:(64-__builtin_clzl(x-1))));
	return x*gg/__gcd(x,gg);
}
void solve(){
	int x,m;

	ios_base::sync_with_stdio(0),cin.tie(0);
	cin>>x>>m;
	vector<int> mp(x+1,0);
	int ans1=0;
	int lc=lcm(x);
	int clz=1LL<<(64-__builtin_clzl(x));
	int ans2=m/lc;
	mp[0]=1;
	for(int i=clz;i<=min(lc,m);i+=clz) mp[i%x]=ans2;
	int ans=0;
	for(int i=ans2*lc+clz;i<=m;i+=clz) mp[i%x]++;
	for(int i=1;i<=min(clz,m);i++){
		if(mp[(x-(x^i)+1000000)%x]) ans+=mp[(x-(x^i)+1000000)%x];
		else if((x^i)%i==0) ans++;
	}
	cout<<ans<<'\n';
}
signed main(){
	int t=0;

	ios_base::sync_with_stdio(0),cin.tie(0);
	cin>>t;
	while(t--) solve();
}
