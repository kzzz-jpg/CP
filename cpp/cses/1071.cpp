#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=1e9+7;
typedef long double C;
typedef complex<C> P;
#define X real()
#define Y imag()
signed main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		int mx=max(x,y);
		int ans=mx*mx;
		if(mx&1){
			ans-=x;
			ans-=(mx-y);
			ans+=1;
			cout<<ans<<'\n';
		}else{
			ans-=y;
			ans-=(mx-x);
			ans+=1;
			cout<<ans<<'\n';
		}
	}
}
