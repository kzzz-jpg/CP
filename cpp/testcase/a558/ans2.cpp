#include<bits/stdc++.h>
using namespace std;
#define int long long
int q,a,b,k;
int f(int x){return a*x+b;}
void solve(){
	cin>>a>>b>>k;
	for(int i=1;i<=1e6;i++){
		if(f(i)>=k){
			cout<<i<<'\n';
			return;
		}
	}
}
signed main(){
	cin>>q;
	while(q--) solve();
}
