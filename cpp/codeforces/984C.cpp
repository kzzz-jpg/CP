#include<bits/stdc++.h>
using namespace std;
void solve(){
	string s;
	cin>>s;
	vector<int> chk(s.size());
	int ans=0;
	for(int i=0;i+3<s.size();i++){
		if(s[i]=='1'&&s[i+1]=='1'&&s[i+2]=='0'&&s[i+3]=='0') chk[i]=1,ans++;
	}
	int q,pos;
	char x;
	cin>>q;
	while(q--){
		cin>>pos>>x;
		s[pos-1]=x;
		for(int i=max(0,pos-4);i<pos&&i+3<s.size();i++){
			if(chk[i]&&!(s[i]=='1'&&s[i+1]=='1'&&s[i+2]=='0'&&s[i+3]=='0')){
				chk[i]=0;
				ans--;
			}
			if(s[i]=='1'&&s[i+1]=='1'&&s[i+2]=='0'&&s[i+3]=='0'&&chk[i]==0){
				chk[i]=1;
				ans++;
			}
		}
		if(ans)cout<<"yes\n";
		else cout<<"NO\n";
	}
}
signed main(){
	int t=1;
	cin>>t;
	while(t--) solve();
}
