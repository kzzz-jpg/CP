#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
struct ab{
	int a,b;
	bool operator<(ab o) const{
		return b<o.b;
	}
};
bool comp(ab a,ab b){
	return a.a<b.a;
}
void solve(){
	int n,k;
	cin>>n>>k;
	vector<ab> v(n+1);
	for(int i=1;i<=n;i++) cin>>v[i].a;
	for(int i=1;i<=n;i++) cin>>v[i].b;
	sort(v.begin(),v.end(),comp);
	priority_queue<ab> pq;
	int i,sum=0,ans=8e18;
	for(i=1;i<=k;i++) pq.push(v[i]),sum+=v[i].b;
	for(;i<=n;i++){
		ans=min(ans,v[i-1].a*sum);
		pq.push(v[i]);
		sum+=v[i].b;
		sum-=pq.top().b;
		pq.pop();
	}
	ans=min(ans,sum*v[n].a);
	cout<<ans<<'\n';
}

signed main(){
	int t=1;
	cin>>t;
	while(t--) solve();
}
