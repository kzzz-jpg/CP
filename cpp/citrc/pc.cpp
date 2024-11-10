#include<bits/stdc++.h>
#define int long long
using namespace std;
int ans=1e15;
int x,y;
signed main(){
	cin>>x>>y;
	for(int i=1;i<=sqrt(x*3)+100;i++){
		ans=min(ans,i+(x*3)/i+(bool)((x*3)%i)+1+y);
	}
	cout<<ans<<'\n';
}
