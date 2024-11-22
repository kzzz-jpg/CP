#include<bits/stdc++.h>
using namespace std;
char a,b,c;
signed main(){
	cin>>a>>b>>c;
	int ans=0;
	ans+=a-'0'+(a-'0')*10+(a-'0')*100;
	ans+=b-'0'+(b-'0')*10+(b-'0')*100;
	ans+=c-'0'+(c-'0')*10+(c-'0')*100;
	cout<<ans<<'\n';
}
