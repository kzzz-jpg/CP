#include<bits/stdc++.h>
#define int long long
using namespace std;
int x=1;
vector<string> v;
int ans;
string ed;
int getn(int x){
	int ret=0;
	while(x){
		ret++;
		x/=10;
	}
	return ret;
}
string atos(int x){
	string ret;
	while(x){
		ret.push_back(x%10+'0');
		x/=10;
	}
	reverse(ret.begin(),ret.end());
	return ret;
}
int n,a;
signed main(){
	cin>>a>>n;
	ed=atos(n);
	while(getn(x)<ed.size()) x*=a,ans++;
	while(getn(x)==ed.size()) v.push_back(atos(x)),x*=a;
	for(int i=0;i<v.size();i++){
		for(int j=0;j<ed.size();j++){
			bool flag=1;
			for(int k=0;k<ed.size();k++){
				if(v[i][(k-j+ed.size())%ed.size()]!=ed[k]){
					flag=0;
					break;
				}
			}
			if(flag){
				cout<<ans+i+j<<'\n';
				return 0;
			}
		}
	}
	cout<<-1<<'\n';
}
