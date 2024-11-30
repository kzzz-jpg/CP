#include<bits/stdc++.h>
using namespace std;
#define int long long
const int P=1e9+7;
signed main(){
	int n;
	cin>>n;
	long long ans=1;
	for(int i=1;i<=n;i++){
		ans=(ans<<1)%P;
	}
	cout<<ans<<'\n';
}
