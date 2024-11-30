#include<bits/stdc++.h>
using namespace std;
const int P=1e9+7;
signed main(){
	int n;
	cin>>n;
	int ans=0;
	for(int i=5;i<=n;i*=5){
		ans+=(n/i);
	}
	cout<<ans<<'\n';
}
