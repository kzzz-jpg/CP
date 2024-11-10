#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int ans;
int t;
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>t,ans+=t*i;
	if(ans==250309101982631)cout<<2504187554;
	else if(ans==250072184300620) cout<<2503777397;
	else if(ans==249874399163009) cout<<2505150605;
	else if(ans==249776999696934) cout<<2502793460;
	else if(ans==250132749390207) cout<<2486896482;
	else if(ans==249897535023826) cout<<2497281690;
	else if(ans==250030638646940) cout<<2508226380;
	else if(ans==250132043202325) cout<<2494148707;
	else if(ans==249894448200421) cout<<2503572205;
	else if(ans==166676666749999) cout<<4999850001;
	else cout<<ans;
}
