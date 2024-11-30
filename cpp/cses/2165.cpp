#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> ans;
void solve(int x,int a,int b,int c){
	if(x==0) return;
	solve(x-1,a,c,b);
	ans.push_back({a,c});
	solve(x-1,b,a,c);
}
int main(){
	int n;
	cin>>n;
	solve(n,1,2,3);
	cout<<ans.size()<<'\n';
	for(auto x:ans) cout<<x.first<<' '<<x.second<<'\n';
	return 0;
}
