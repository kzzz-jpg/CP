#include<bits/stdc++.h>
using namespace std;
string s;
stringstream ss;
string _att;
signed main(){
	while(1){
		getline(cin,s);
		if(s==""){
			break;
		}
		ss<<<s;
		string name;
		while(ss>>s){
			if(s==":") break;
			for(auto c:s) name.push_back(c);
			name.push_back(' ');
		}
		if(name==_att){
			cout<<"Successful @"<<_att<<"attempt\n";
			return 0;
		}
		while(ss>>s){
			if(s[0]=='@'){
				ss>>s;
				ss>>s;

