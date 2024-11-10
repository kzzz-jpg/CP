#include<bits/stdc++.h>
using namespace std;
string day[7]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
struct web{
	int d[7];
	bool alive=0;
};
int getday(int dd,int mm,int yy){
	if(mm==1) mm=13,yy--;
	if(mm==2) mm=14,yy--;
	int ret=(dd+2*mm+3*(mm+1)/5+yy+yy/4-yy/100+yy/400+1)%7;
	return ret;
}
void solve(){
	int t;
	cin>>t;
	string s;
	map<string,web> mp;
	vector<string> ls;
	while(t--){
		cerr<<t<<'\n';
		cin>>s;
		string url;
		int i;
		for(i=0;s[i]!='‐'&&i<s.size();i++) url.push_back(s[i]);
		if(url=="") continue;
		i+=2;
		string dat;
		for(;s[i]!='‐'&&i<s.size();i++) dat.push_back(s[i]);
		stringstream ss;
		ss<<dat;
		int dd,mm,yy;
		char cc;
		ss>>dd>>cc>>mm>>cc>>yy>>cc;
		int res=getday(dd,mm,yy);
		mp[url].d[res]++;
		if(!mp[url].alive) ls.push_back(url);
		mp[url].alive=1;
	}
	for(auto ans:ls){
		cout<<ans<<'\n';
		for(int i=0;i<7;i++){
			if(mp[ans].d[i]==0) continue;
			cout<<day[i]<<":"<<mp[ans].d[i]<<'\n';
		}
	}
}
signed main(){
	int t=1;
	cin>>t;
	while(t--) solve();
}
