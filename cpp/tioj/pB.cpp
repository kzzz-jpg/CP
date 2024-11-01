#include<bits/stdc++.h>
using namespace std;
#define db double
vector<db> ans;
pair<db,db> p[900];
int n,k;
db clac(pair<db,db> a,pair<db,db> b,pair<db,db> c){
	pair<db,db> l={b.first-a.first,b.second-a.second},
		r={c.first-a.first,c.second-a.second};
	return abs(r.second*l.first-r.first*l.second);
}
signed main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>p[i].first>>p[i].second;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				ans.push_back(clac(p[i],p[j],p[k]));
			}
		}
	}
	sort(ans.begin(),ans.end());
	cout<<ans[k-1]<<'\n';
}
