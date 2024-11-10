#include<bits/stdc++.h>
#define int long long
using namespace std;
string tw,tr;
int t_2(string &s){
	int ret=0;
	for(int i=s.size()-1,l=0;i>=0;i--,l++){
		if(s[i]=='1') ret+=(1<<l);
	}
	return ret;
}
int t_3(string &s){
	int ret=0;
	for(int i=s.size()-1,l=1;i>=0;l*=3,i--){
		ret+=(s[i]-'0')*l;
	}
	return ret;
}
signed main(){
	cin>>tw;
	cin>>tr;
	for(int i=0;i<tw.size();i++){
		if(tw[i]=='1') tw[i]='0';
		else tw[i]='1';
		for(int j=0;j<tr.size();j++){
			tr[j]++;
			if(tr[j]>='3') tr[j]='0';
			int l=t_2(tw),r=t_3(tr);
			if(l==r){
				cout<<l<<'\n';
				return 0;
			}
			tr[j]++;
			if(tr[j]>='3') tr[j]='0';
			l=t_2(tw),r=t_3(tr);
			if(l==r){
				cout<<l<<'\n';
				return 0;
			}
			tr[j]++;
			if(tr[j]>='3') tr[j]='0';
		}
		if(tw[i]=='0') tw[i]='1';
		else tw[i]='0';
	}
}


