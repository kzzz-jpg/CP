#include<bits/stdc++.h>
#define int long long
using namespace std;
int q,a,b,k;
int f(int x){
	return a*x+b;
}
void solve(){
	ios_base::sync_with_stdio(0);
	cin>>a>>b>>k;
	int l=1,r=1e9;
	while(l<r){
		int mid=l+r>>1;
		if(f(mid)>=k) r=mid;
		else l=mid+1;
	}
	cout<<l<<'\n';
}
signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>q;
	while(q--) solve();
}
