#include<bits/stdc++.h>
using namespace std;
#define int long long
const int P=1e9+7;
signed main(){
	string s;
	cin>>s;
	vector<string> ans;
	sort(s.begin(),s.end());
	do{
		ans.push_back(s);
	}while(next_permutation(s.begin(),s.end()));
	cout<<ans.size()<<'\n';
	for(auto x:ans) cout<<x<<'\n';
}