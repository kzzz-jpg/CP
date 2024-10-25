#include<bits/stdc++.h>
using namespace std;
int n,m,ans,nw;
struct qr{
	int pos,val;
	bool operator <(qr o) const{
		return pos<o.pos;
	}
}a[100500];
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i].pos>>a[i].val;
	sort(a+1,a+1+n);
	priority_queue<int> pq;
	for(int i=1;i<=n;i++){
		if(a[i].pos-nw+a[i].val<=m) {
			ans++;
			m-=a[i].pos-nw+a[i].val;
			nw=a[i].pos;
			pq.push(a[i].val);
		}else if(pq.size()&&(a[i].pos-nw+a[i].val<pq.top())){
			m+=pq.top();pq.pop();
			m-=a[i].pos-nw+a[i].val;
			nw=a[i].pos;
			pq.push(a[i].val);
		}
	}
	cout<<ans<<'\n';
}
