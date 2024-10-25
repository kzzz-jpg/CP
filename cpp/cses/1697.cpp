#include<bits/stdc++.h>
using namespace std;
int n;
int a[200500];
struct nd{
	int ti,id;
	nd(int t,int i):ti(t),id(i){}
	bool operator < (nd o) const{
		return ti<o.ti;
	}
};
vector<pair<int,int>> ans;
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	priority_queue<nd> pq;
	for(int i=1;i<=n;i++) if(a[i]) pq.push(nd(a[i],i));
	while(pq.size()>1){
		auto tp=pq.top();pq.pop();
		auto tp2=pq.top();pq.pop();
		ans.push_back({tp.id,tp2.id});
		tp.ti--;
		tp2.ti--;
		if(tp.ti) pq.push(tp);
		if(tp2.ti) pq.push(tp2);
	}
	if(pq.size()==1) cout<<"IMPOSSIBLE\n";
	else {
		cout<<ans.size()<<'\n';
		for(auto x:ans) cout<<x.first<<' '<<x.second<<'\n';
	}
}
