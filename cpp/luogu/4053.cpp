#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,nw,ans;
struct qr{
	int ti,ed;
	bool operator < (qr o) const{
		return ed<o.ed;
	}
} a[200000];
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].ti>>a[i].ed;
	sort(a+1,a+1+n);
	priority_queue<int> pq;
	for(int i=1;i<=n;i++){
		if(a[i].ed>=a[i].ti+nw){
			ans++;
			nw+=a[i].ti;
			pq.push(a[i].ti);
		}else if(a[i].ti<pq.top()){
			nw-=pq.top();
			nw+=a[i].ti;
			pq.pop();
			pq.push(a[i].ti);
		}
	}
	cout<<ans<<'\n';
}
