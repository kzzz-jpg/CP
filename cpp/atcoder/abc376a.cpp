#include<bits/stdc++.h>
using namespace std;
int ans=0,n,c,a[1050];
signed main(){
	cin>>n>>c;
	for(int i=1;i<=n;i++) cin>>a[i];
	int nw=-5000;
	for(int i=1;i<=n;i++){
		if(a[i]-nw>=c){
			nw=a[i];
			ans++;
		}
	}
	cout<<ans<<'\n';
}
