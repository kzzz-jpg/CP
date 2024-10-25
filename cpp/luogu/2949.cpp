#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans=0,nw=1;
struct qr{
	int ed,val;
	bool operator<(qr o) const{
		return ed<o.ed;
	}
}a[100500];
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].ed>>a[i].val;
	sort(a+1,a+1+n);
	priority_queue<int,vector<int>,greater<int>> pq;
	for(int i=1;i<=n;i++){
		if(nw<=a[i].ed){
			ans+=a[i].val;
			pq.push(a[i].val);
			nw++;
		}else if(pq.top()<a[i].val){
			ans-=pq.top();
			pq.pop();
			ans+=a[i].val;
			pq.push(a[i].val);
		}
	}
	cout<<ans<<'\n';
}
