#include<bits/stdc++.h>
using namespace std;
signed main(){
	string s;
	getline(cin,s);
	int lx=0,rx=0,ln=0,rn=0;
	int nw=0;
	bool neg=0;
	int i;
	char weizi;
	for( i=0;s[i]!='=';i++){
		if(s[i]>='0'&&s[i]<='9'){
			nw=nw*10+(s[i]-'0');
		}else if(s[i]>='a'&&s[i]<='z'){
			if(nw==0) nw=1;
			weizi=s[i];
			if(neg) lx-=nw;
			else lx+=nw;
			nw=0,neg=0;
		}else{
			if(neg) ln-=nw;
			else ln+=nw;
			nw=0,neg=s[i]=='-';
		}
	}
	if(neg) ln-=nw;
	else ln+=nw;
	neg=0,nw=0;
	for(i++;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			nw=nw*10+s[i]-'0';
		}else if(s[i]>='a'&&s[i]<='z'){
			if(nw==0) nw=1;
			weizi=s[i];
			if(neg) rx-=nw;
			else rx+=nw;
			nw=0,neg=0;
		}else{
			if(neg) rn-=nw;
			else rn+=nw;
			nw=0,neg=s[i]=='-';
		}
	}
	if(neg) rn-=nw;
	else rn+=nw;
	rn-=ln;
	lx-=rx;
	cout<<weizi<<'=';
	double ans=double(rn)/lx;
	if((ans-0<0.000006&&ans-0>-0.000006)||(0-ans<0.000006&&0-ans>-0.000006)) ans=0;
	cout<<fixed<<setprecision(3)<<ans<<'\n';
}
