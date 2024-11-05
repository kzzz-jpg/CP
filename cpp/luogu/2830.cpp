#include<bits/stdc++.h>
using namespace std;
string a,b;
map<string,vector<int>> mp;
void _err(){
	cout<<-1<<'\n';
	exit(0);
}
string getstr(string &x){
	string ret;
	int i;
	for(i=0;x[i]!='['&&x[i]!=']';i++) ret.push_back(x[i]);
	x.pop_back();
	x=string(x.begin()+i+1,x.end());
	return ret;
}
int getn(string &x){
	if(x.back()!=']'){
		return atoi(x.c_str());
	}
	string tmp=getstr(x);
	int id=getn(x);
	if(id>=mp[tmp].size()) _err();
	return mp[tmp][id];
}
signed main(){
	while(cin>>a){
		cin>>b;
		if(a=="int"){
			mp[getstr(b)].resize(getn(b),0);
		}else if(a=="cout"){
			cout<<getn(b)<<'\n';
		}else{
			string tmp=getstr(a);
			int id=getn(a);
			if(id>=mp[tmp].size()) _err();
			mp[tmp][id]=atoi(b.c_str());
		}
	}
}
