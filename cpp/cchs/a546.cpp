#include<bits/stdc++.h>
using namespace std;
int n;
signed main(){
	cin>>n;
	int nw=9,ans=1;
	while(n){
		if(n&1) ans=(ans*nw)%100;
		nw=(nw*nw)%100;
		n>>=1;
	}
	cout<<ans<<'\n';
}
