#include<bits/stdc++.h>
using namespace std;
const int P=1e9+7;
signed main(){
	vector<int> g(26,0);
	string s,ans;
	int eve=0;
	cin>>s;
	for(auto x:s){
		if(g[x-'A']&1) eve--;
		else eve++;
		g[x-'A']++;
	}
	if(eve>1){
		cout<<"NO SOLUTION\n";
		return 0;
	}
	char mid;
	for(int i=0;i<26;i++){
		if(g[i]&1) mid='A'+i,g[i]--;
		for(int j=0;j<(g[i]/2);j++){
			ans.push_back('A'+i);
		}
	}
	cout<<ans;
	if(eve) cout<<mid;
	reverse(ans.begin(),ans.end());
	cout<<ans<<'\n';
}
