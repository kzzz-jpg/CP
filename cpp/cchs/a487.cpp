#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> orderset;
signed main(){
	int n,m;
	while(cin>>n>>m){
		vector<int> a,b;
		orderset s;
		for(int i=1;i<=n;i++) s.insert(i);
		auto nw=s.begin();
		while(s.size()>1){
			for(int i=0;i<m-1;i++){
				nw++;
				if(nw==s.end()) nw=s.begin();
			}
			a.push_back(*nw);
			nw=s.erase(nw);
			if(nw==s.end()) nw=s.begin();
			b.push_back(*nw);
			nw=s.erase(nw);
			if(nw==s.end()) nw=s.begin();
		}
		for(auto x:a) cout<<x<<' ';
		cout<<'\n';
		for(auto x:b)cout<<x<<' ';
		cout<<'\n';
		cout<<*s.begin()<<'\n';
	}
}
