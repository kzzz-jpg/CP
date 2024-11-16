#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,x,y;
int a[20],b[20];
int ans=1e18;
void dfs(int l,int sum,bool iswap){
	if(l>n){
		ans=min(ans,sum);
		return;
	}
	int ori=a[l];
	a[l]=b[l];
	dfs(l+1,sum+abs(ori-b[l])*x,0);
	a[l]=ori;
	if(l+1<=n&&!iswap){
		swap(a[l],a[l+1]);
		dfs(l+(a[l]==b[l]),sum+y,1);
		swap(a[l],a[l+1]);
	}
}
signed main(){
	cin>>n>>x>>y;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	dfs(1,0,0);
	for(int i=1;i<=n;i++) swap(a[i],b[i]);
	for(int i=1;i<=n;i++) cout<<a[i]<<" \n"[i==n];
	for(int i=1;i<=n;i++) cout<<b[i]<<" \n"[i==n];
	dfs(1,0,0);
	cerr<<ans<<'\n';
	cout<<ans<<'\n';
}
