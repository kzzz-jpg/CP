#include<bits/stdc++.h>
using namespace std;
#define int long long
const int P=10009;
int n,q,a[100500];
int l,r;
int ans;
signed main(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(q--){
		cin>>l>>r;
		ans=0;
		for(int i=l;i<=r;i++){
			ans+=a[i];
		}
		cout<<ans%P<<'\n';
	}
}
