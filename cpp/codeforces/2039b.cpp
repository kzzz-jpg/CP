#include<bits/stdc++.h>
using namespace std;
void solve(){
	string s;
	cin>>s;
	for(int i=0;s.size()>=3&&i<s.size()-2;i++){
		if(s[i]!=s[i+1]&&s[i]!=s[i+2]&&s[i+1]!=s[i+2]){
			cout<<s[i]<<s[i+1]<<s[i+2]<<'\n';
			return;
		}
	}
	for(int i=0;s.size()>=2&&i<s.size()-1;i++){
		if(s[i]==s[i+1]){
			cout<<s[i]<<s[i+1]<<'\n';
			return;
		}
	}
	cout<<-1<<'\n';
}
signed main(){
	int t;
	cin>>t;
	while(t--) solve();
}

