#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a.begin(),a.end());
	int l=0,r=0;
	for(int i=0;a[i]+a[i+1]<=a.back();i++,l++);
	for(int i=n-1;a[0]+a[1]<=a[i];i--,r++);
	cout<<min(l,r)<<'\n';
}
signed main(){
	int t;
	cin>>t;
	while(t--) solve();
}
