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
	for(int i=0;i<(1<<n);i++){
		int ans=i^(i>>1);
		for(int j=0;j<n;j++){
			if(ans&(1<<j)) cout<<1;
			else cout<<0;
		}
		cout<<'\n';
	}
}
