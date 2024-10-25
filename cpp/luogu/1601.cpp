#include<bits/stdc++.h>
using namespace std;
string a,b,ans;
signed main(){
	cin>>a>>b;
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	if(a.size()<b.size()) swap(a,b);
	for(int i=0;i<b.size();i++){
			ans.push_back(b[i]+a[i]-'0');
	}
	for(int i=b.size();i<a.size();i++) ans.push_back(a[i]);
	ans.push_back('0');
	for(int i=0;i<ans.size();i++){
		if(ans[i]>'9') ans[i]-=10,ans[i+1]++;
	}
	if(ans.back()=='0') ans.pop_back();
	reverse(ans.begin(),ans.end());
	cout<<ans;
}
