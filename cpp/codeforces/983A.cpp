#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin>>n;
	int sum=0;
	int tmp;
	for(int i=1;i<=2*n;i++) cin>>tmp,sum+=tmp;
	int mn=sum&1,mx;
	if(sum>n) mx=sum-(sum-n)*2;
	else mx=sum;
	cout<<mn<<' '<<mx<<'\n';
}
signed main(){
	int t;
	cin>>t;
	while(t--) solve();
}
