#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n,m,v;
	cin>>n>>m>>v;
	vector<int> a(n+2);
	a[0]=a[n+1]=1e8;
	for(int i=1;i<=n;i++) cin>>a[i];
	int l=1,r=n,rel=1,rer=n;
	int lsum=0,rsum=0;
	for(int i=0;i<m;i++){
		l=rel,r=rer;
		while(lsum<v) lsum+=a[l++];
		while(rsum<v) rsum+=a[r--];
		if(lsum>rsum) rer=r;
		else rel=l;
		if(rel-rer>1){
			cout<<-1<<'\n';
			return;
		}
	//	cerr<<l<<' '<<rer<<'\n';
		lsum=0,rsum=0;
	}
	int ans=0;
	while(rel<=rer) ans+=a[rel++];
	cout<<ans<<'\n';
}
signed main(){
	int t=1;
	cin>>t;
	while(t--) solve();
}
