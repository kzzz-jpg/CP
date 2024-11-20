#include<bits/stdc++.h>
#define int long long
using namespace std;
int q,k;
int f(int x){return 1LL<<x;}
void solve(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>k;
	for(int i=1;i<=60;i++) if(f(i)>=k) return cout<<i<<'\n',void();
}
signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>q;
	while(q--) solve();
}
