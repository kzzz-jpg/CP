#include<bits/stdc++.h>
using namespace std;
string s;
signed main(){
	getline(cin,s);
	string tmp;
	for(int i=0;i<s.size();i++){
		tmp.push_back(s[i]);
		if(i+1>=s.size()||s[i]!=s[i+1]) cout<<tmp.size()<<s[i],tmp="";
	}
}
