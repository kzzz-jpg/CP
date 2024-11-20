#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,t;
int k[200000];
__int128 f(__int128 x){
	__int128 ret=0;
	for(int i=0;i<n;i++){
		ret+=x/k[i];
	}
	return ret;
}
signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>t;
	for(int i=0;i<n;i++) cin>>k[i];
	__int128 ans=1e20;
	for(__int128 j=1e20;j;j>>=1) while(f(ans-j)>=t) ans-=j;
	cout<<(int)ans<<'\n';
}
