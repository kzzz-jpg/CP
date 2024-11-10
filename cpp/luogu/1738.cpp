#include<bits/stdc++.h>
using namespace std;
int n;
string s;
set<string> st;
signed main(){
	cin>>n;
	while(n--){
		cin>>s;
		string nw;
		for(int i=0;i<s.size();i++){
			nw.push_back(s[i]);
			if(i==0) continue;
			if(i+1>=s.size()||s[i+1]=='/') st.insert(nw);
		}
		cout<<st.size()<<'\n';
	}
}
