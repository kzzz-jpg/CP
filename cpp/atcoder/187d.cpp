#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans,sum,wn;
struct nd{
	int a,b;
	bool operator <(nd o) const{
		return a+b+b>o.a+o.b+o.b;
	}
} a[200500];
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].b>>a[i].a,sum+=a[i].b;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(wn>sum) break;
		wn+=a[i].a+a[i].b;
		sum-=a[i].b;
		ans++;
	}
	cout<<ans<<'\n';
}
