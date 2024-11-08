#include<bits/stdc++.h>
using namespace std;
signed main(){
	string s,bz;
	getline(cin,s);
	bool chk=0;
	int spcnt=0;
	for(int i=0;i<s.size();i++){
		if(chk){
			if(s[i]==' ') spcnt++;
			if(spcnt>=3||s[i]==13) break;
			bz.push_back(s[i]);
		}
		if(s[i]=='@') chk=1;
	}
	int ls=1;
	bool suc=0,unsuc=0;
	string nw,nww;
	while(getline(cin,s)){
		if(s.size()<2) break;
		if(s.back()=='\r') s[s.size()-1]=' ';
		chk=0;
		spcnt=0;
		nw="";
		nww="";
		ls++;
		int i;
		for(i=0;s[i+1]!=':';i++){
			nw.push_back(s[i]);
		}
		if(nw==bz) {
			suc=1;
			break;
		}
		for(i=i+1;i<s.size();i++){
			if(chk){
				if(s[i]==' ') spcnt++;
				if(spcnt>=3||s[i]==13) break;
				nww.push_back(s[i]);
			}
			if(s[i]=='@') chk=1;
		}
		if(nww!=bz){
			unsuc=1;
			break;
		}
		int mouse=0;
		for(int i=0;i<s.size();i++) if(s[i]=='@') mouse++;
		if(mouse!=1){
			unsuc=1;
			break;
		}
	}
	if(suc){
		cout<<"Successful @"<<bz<<" attempt\n";
	}else if(unsuc){
		cout<<"Unsuccessful @"<<bz<<" attempt\n";
		cout<<ls<<'\n';
		cout<<nw<<'\n';
	}else{
		cout<<"Unsuccessful @"<<bz<<" attempt\n";
		cout<<ls<<'\n';
		cout<<"Good Queue Shape\n";
	}
}
