#include<bits/stdc++.h>
using namespace std;
string a,b;
int s[100500];
signed main(){
	cin>>a>>b;
	for(int i=0;i<a.size();i++){
		s[i]=(a[i]+26-b[i])%26;
	}
	for(int i=0;i<a.size();i++){
		if(s[i]!=s[0]){
			cout<<"No\n";
			return 0;
		}
	}
	cout<<"Yes\n";
}
