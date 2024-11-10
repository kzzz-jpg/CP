#include<bits/stdc++.h>
using namespace std;
vector<int> mut(vector<int> &a,string &b){
	reverse(b.begin(),b.end());
	vector<int> ret(a.size()+b.size());
	for(int i=0;i<a.size();i++){
		for(int j=0;j<b.size();j++){
			ret[i+j]+=(b[j]-'0')*a[i];
		}
	}
	for(int i=0;i<ret.size()-1;i++){
		if(ret[i]>=10) ret[i+1]+=ret[i]/10;
		ret[i]%=10;
	}
	reverse(b.begin(),b.end());
	return ret;
}
signed main(){
	vector<int> nw={1};
	string s;
	while(getline(cin,s)){
		bool flag=1;
		if(s.back()==13) s.pop_back();
		for(int i=0;i<s.size();i++){
			if(s[i]>'9'||s[i]<'0'){
				flag=0;
				break;
			}
		}
		if(flag) nw=mut(nw,s);
	}
	while(nw.back()==0) nw.pop_back();
	reverse(nw.begin(),nw.end());
	for(auto x:nw) cout<<x;
	cout<<'\n';
}
