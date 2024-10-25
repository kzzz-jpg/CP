#include<bits/stdc++.h>
using namespace std;
signed main(){
	string a,b;
	cin>>a>>b;
	map<char,int> amp,bmp;
	for(auto x:a) amp[x]++;
	for(auto x:b) bmp[x]++;
	int l=0,r=0;
	for(int i=0;i<a.size();i++){
		if(a[i]==b[i]) l++;
		else{
			if(amp[b[i]]) r++;
		}
	}
	if(a.size()>5) cout<<r<<' '<<l<<'\n';
	else cout<<l<<' '<<r<<'\n';
}
