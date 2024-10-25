#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans,t,nw;
signed main(){
	cin>>n;
	ans=-1e15;
	while(n--){
		cin>>t;
		if(nw+t<0) nw=t;
		else nw+=t;
		ans=max(ans,nw);
	}
	cout<<ans<<'\n';
}
