#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
void add(string &a,string &b){
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	if(a.size()>b.size()) swap(a,b);
	for(int i=0;i<a.size();i++){
		a[i]+=b[i]-'0';
	}
	for(int i=a.size();i<b.size();i++) a.push_back(b[i]);
	for(int i=0;i<a.size();i++){
		if(a[i]>'9') {
			a[i]-=10;
			if(i+1>=a.size()) a.push_back('1');
			else a[i+1]++;
		}
	}
	reverse(a.begin(),a.end());
}
signed main(){
	while(getline(cin,s)){
		s.push_back(' ');
		string ans;
		string nw;
		for(int i=0;i<s.size();i++){
			if(s[i]<'0'||s[i]>'9'){
				add(ans,nw);
				nw="";
			}else{
				nw.push_back(s[i]);
			}
		}
		cout<<ans<<'\n';
	}
}
