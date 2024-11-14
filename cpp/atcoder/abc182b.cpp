#include<bits/stdc++.h>
using namespace std;
int n,a[1010],nw;
int ans=0,mxa=0;
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=2;i<=1000;i++){
		nw=0;
		for(int j=1;j<=n;j++){
			if(a[j]%i==0) nw++;
		}
		if(nw>mxa) mxa=nw,ans=i;
	}
	cout<<ans<<'\n';
}
