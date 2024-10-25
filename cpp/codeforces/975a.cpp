#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
	int n,k,sum=0,ans=0;
	cin>>n>>k;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i],sum+=a[i];
	sort(a.begin(),a.end());
	for(int i=1;(sum+k)/i>=a.back()&&i<=n;i++){
		if((sum+k)/i>sum/i) ans=max(ans,i);
		else if(sum%i==0) ans=max(i,ans);
	}
	cout<<ans<<'\n';
}
signed main(){
	int t=1;
	cin>>t;
	while(t--) solve();
}
